#include <iostream>
#include <utility>
#include <pthread.h>
#include <vector>
#include <unistd.h>
#include <stdio.h>

pthread_mutex_t mutex;
FILE *in_stream = stdin;
FILE *out_stream = stdout;

enum class Gender { MALE, FEMALE, NONE };

struct Person {
    inline static int instances = 0;
    std::string name;
    Gender gender;
    int id;
    Person(std::string name, Gender gender) : name(std::move(name)), gender(gender) {
        id = instances;
        ++instances;
    }
};

struct Room {
    std::vector<Person *> persons;
    int capacity;
    int room_number;

    Room() : capacity(0), room_number(0) {
    }

    Room(int capacity, int room_number) : capacity(capacity), room_number(room_number) {
    }

    void addPerson(Person *person) {
        persons.push_back(person);
    }

    void removePerson(Person *person) {
        size_t pos = 0;
        for (;pos < persons.size(); ++pos) {
            if (persons[pos]->id == person->id) {
                break;
            }
        }

        if (pos >= persons.size()) {
            return;
        }

        persons.erase(persons.begin() + pos);
    }

    bool isFree() {
        return persons.size() != capacity;
    }

    Gender getRoomGender() {
        return persons.empty() ? Gender::NONE : persons[0]->gender;
    }
};

const int kSingleRoomsAmount = 10;
const int kDoubleRoomsAmount = 15;
Room *rooms[kSingleRoomsAmount + kDoubleRoomsAmount];

Room *findRoom(Gender gender) {
    for (Room *room : rooms) {
        if (!room->isFree()) {
            continue;
        }

        if (room->capacity == 1 || room->getRoomGender() == gender ||
            room->getRoomGender() == Gender::NONE) {
            return room;
        }
    }

    return nullptr;
}

pthread_barrier_t barrier;

void *takeRoom(void *thread_parameter) {
    Person *person = static_cast<Person *>(thread_parameter);

    pthread_barrier_wait(&barrier);
    usleep(rand() % 2000 + 150);
    pthread_mutex_lock(&mutex);

    Room *room = findRoom(person->gender);
    if (!room) {
        printf("%s guest with id %d without room :(\n", person->gender == Gender::MALE ? "Male" : "Female", person->id);
        pthread_mutex_unlock(&mutex);
        return nullptr;
    }
    room->addPerson(person);
    printf("%s guest with id %d take %d\n", person->gender == Gender::MALE ? "Male" : "Female", person->id, room->room_number);
    pthread_mutex_unlock(&mutex);

    usleep(rand() % 1000 + 150);

    pthread_mutex_lock(&mutex);

    room->removePerson(person);
    printf("%s guest with id %d free room %d!!\n", person->gender == Gender::MALE ? "Male" : "Female", person->id, room->room_number);
    pthread_mutex_unlock(&mutex);
    usleep(10);

    return nullptr;
}

void initializeRooms() {
    for (int i = 0; i < kSingleRoomsAmount; ++i) {
        rooms[i] = new Room(1, i + 1);
    }

    for (int i = 0; i < kDoubleRoomsAmount; ++i) {
        rooms[kSingleRoomsAmount + i] = new Room(2, kSingleRoomsAmount + i + 1);
    }
}


int main() {
    std::vector<Person *> persons;

    initializeRooms();

    pthread_mutex_init(&mutex, nullptr);

    int persons_number = 100;
    pthread_barrier_init(&barrier, nullptr, persons_number);

    for (int i = 0; i < persons_number; ++i) {
        persons.push_back(new Person("Cool name", i % 2 == 0 ? Gender::MALE : Gender::FEMALE));
    }

    pthread_t threads[persons_number];
    size_t i = 0;
    for (auto person_ptr : persons) {
        pthread_create(&threads[i], nullptr, takeRoom, static_cast<void *>(person_ptr));
        ++i;
    }

    for (auto thread : threads) {
        pthread_join(thread, nullptr);
    }

    for (Room *ptr : rooms) {
        delete ptr;
    }

    for (Person *ptr : persons) {
        delete ptr;
    }

    pthread_barrier_destroy(&barrier);
    pthread_mutex_destroy(&mutex);

    return 0;
}
