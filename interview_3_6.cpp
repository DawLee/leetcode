// coding Interview 3_6
// 动物收容所
// easy

#include "leetcode.h"
using namespace std;

class AnimalShelf {
    vector<queue<vector<int>>> animals;
    int typeOfAnimal;

  public:
    AnimalShelf() {
        typeOfAnimal = 2;
        animals.resize(typeOfAnimal, queue<vector<int>>());
    }

    void enqueue(vector<int> animal) { animals[animal[1]].emplace(animal); }

    vector<int> dequeueAny() {
        vector<int> res = {-1, -1};
        if (animals[0].empty() && animals[1].empty()) {
            return res;
        } else if (animals[0].empty()) {
            return dequeueDog();
        } else if (animals[1].empty()) {
            return dequeueCat();
        } else {
            if (animals[0].front()[0] <= animals[1].front()[0]) {
                return dequeueCat();
            }
            return dequeueDog();
        }
    }

    vector<int> dequeueDog() {
        if (animals[1].empty()) {
            return {-1, -1};
        }
        vector<int> res = animals[1].front();
        animals[1].pop();
        return res;
    }

    vector<int> dequeueCat() {
        if (animals[0].empty()) {
            return {-1, -1};
        }
        vector<int> res = animals[0].front();
        animals[0].pop();
        return res;
    }
};

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */