#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;

class horse {
protected:
    string name;
    float distance;

public:
    horse(string n = "Horse") : name(n), distance(0.0f) {}
    virtual void horse_tick() { distance += 0.1f + (rand() % 10) / 100.0f; }
    float getDistance() const { return distance; }
    string getName() const { return name; }
    virtual ~horse() {}
};

class comhorse : public horse {
public:
    comhorse(string n = "ComHorse") : horse(n) {}

    void horse_tick(const vector<comhorse*>& hArray) {
        float maxDist = 0;
        comhorse* leader = nullptr;

        for (auto h : hArray) {
            if (h->getDistance() > maxDist) {
                maxDist = h->getDistance();
                leader = h;
            }
        }

        distance += 0.1f + (rand() % 10) / 100.0f;

        if (leader == this) {
            for (auto h : hArray) {
                if (h != this && (distance - h->getDistance() <= 0.1f)) {
                    distance += 0.05f;
                    break;
                }
            }
        }
    }
};

class comtrack {
    vector<comhorse*> hArray;

public:
    comtrack(const vector<string>& names) {
        for (auto& n : names)
            hArray.push_back(new comhorse(n));
        srand(static_cast<unsigned int>(time(0)));
    }

    void race(int laps) {
        for (int i = 0; i < laps; i++) {
            for (auto h : hArray)
                h->horse_tick(hArray);  // pass the vector to each horse

            for (auto h : hArray)
                cout << h->getName() << ": " << h->getDistance() << " ";
            cout << endl;

            this_thread::sleep_for(chrono::milliseconds(200));
        }
    }

    ~comtrack() {
        for (auto h : hArray)
            delete h;
    }
};

int main() {
    vector<string> names = {"Lightning", "Thunder", "Blaze"};
    comtrack track(names);
    track.race(20);
    return 0;
}
