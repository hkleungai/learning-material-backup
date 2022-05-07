//modify and submit this file only
#include "pa3.h"
#include <iostream>
using namespace std;
//you are NOT allowed to include any additional library; see FAQ


//the following are our own helper functions, not to be provided to students but students are free to create their own
//========================================================================================================
TrainCar* createTrainCar(CarType type, int maxLoad, int load, TrainCar* prev, TrainCar* next) //create and return a new train car with the given parameters
{
    // return new TrainCar{cargoType, maxLoad, load, prev, next}; //this is simpler 
    TrainCar* newCar = new TrainCar;
    newCar->type = type;
    newCar->maxLoad = maxLoad;
    newCar->load = load;
    newCar->prev = prev;
    newCar->next = next;
    return newCar;
}

const TrainCar* locateCar(const TrainCar* head, int position) //return the pointer to the car at the given position
{ //assume position >= 0 and position < length of train
    while(position--)
        head = head->next;
    return head;
}

TrainCar* locateCar(TrainCar* head, int position) //return the pointer to the car at the given position
{ //assume position >= 0 and position < length of train
    while(position--)
        head = head->next;
    return head;
}

int getCarLength(const TrainCar* head)
{
    int length = 0;
    while(head)
    {
        length++;
        head = head->next;
    }
    return length;
}
//========================================================================================================


TrainCar* createTrainHead()
{
    return createTrainCar(HEAD, 0, 0, nullptr, nullptr); 
}

bool addCar(TrainCar* head, int position, CarType type, int maxLoad)
{
    int carLength = getCarLength(head);
    if(position < 1 || position > carLength || type == HEAD || maxLoad <= 0) //let's assume head is not nullptr for all functions
        return false;    
    TrainCar* newCar = createTrainCar(type, maxLoad, 0, nullptr, nullptr);
    if(position == carLength) //adding a new car at the end of the train
    {
        TrainCar* last = locateCar(head, position-1);
        last->next = newCar;
        newCar->prev = last;
    }
    else
    {
        TrainCar* cur = locateCar(head, position);
        cur->prev->next = newCar;
        newCar->prev = cur->prev;
        newCar->next = cur;
        cur->prev = newCar;
    }
    return true;
}

bool deleteCar(TrainCar* head, int position)
{
    if(position < 1 || position >= getCarLength(head))
        return false;
    TrainCar* cur = locateCar(head, position);
    cur->prev->next = cur->next;
    if(cur->next)
        cur->next->prev = cur->prev;
    delete cur;
    return true;
}

bool swapCar(TrainCar* head, int a, int b)
{
    //note: an alterative solution is to swap the values inside car A and car B, which may be shorter

    int carLength = getCarLength(head);
    if(a < 1 || a >= carLength || b < 1 || b >= carLength)
        return false;

    if(a==b)
        return true;

    if(a > b) //make sure a is smaller than b
    {
        int temp = a;
        a = b;        
        b = temp;
    }

    TrainCar* carA = locateCar(head, a);
    TrainCar* carB = locateCar(head, b);
    
    if(b - a == 1) //carA and carB are adjacent
    {
        TrainCar* carAPrev = carA->prev;
        // TrainCar* carANext = carA->next;
        // TrainCar* carBPrev = carB->prev;
        TrainCar* carBNext = carB->next;

        carAPrev->next = carB;
        carB->prev = carAPrev;
        
        carB->next = carA;
        carA->prev = carB;

        carA->next = carBNext;
        if(carBNext)
            carBNext->prev = carA;
    }
    else
    {
        TrainCar* carAPrev = carA->prev;
        TrainCar* carANext = carA->next;
        TrainCar* carBPrev = carB->prev;
        TrainCar* carBNext = carB->next;

        carAPrev->next = carB;
        carB->prev = carAPrev;

        carB->next = carANext;
        if(carANext)
            carANext->prev = carB;

        carBPrev->next = carA;
        carA->next = carBNext;

        if(carBNext)
            carBNext->prev = carA;
        carA->prev = carBPrev;
    }

    return true;
}

void sortTrain(TrainCar* head, bool ascending)
{
    int carLength = getCarLength(head);
    for(int i=1; i<carLength; i++) //note we have to ignore the head
    {
        for(int j=1; j<carLength-i; j++)
        {
            if((locateCar(head, j)->load > locateCar(head, j+1)->load) == ascending)
            {
                swapCar(head, j, j+1);
            }
        }
    }
}

bool load(TrainCar* head, CarType type, int amount)
{
    //first check if it is possible
    int remaining = amount;
    TrainCar* cur = head->next;
    while(cur && remaining>0)
    {
        if(cur->type == type)
            remaining -= (cur->maxLoad - cur->load);
        cur = cur->next;
    }
    if(remaining>0)
        return false;

    //now actually load from the beginning of the train
    remaining = amount;
    cur = head->next;
    while(cur && remaining>0)
    {
        if(cur->type == type)
        {
            remaining -= (cur->maxLoad - cur->load);
            if(remaining >= 0) //complete load
                cur->load = cur->maxLoad;
            else //incomplete load
                cur->load = cur->maxLoad+remaining;
        }
        cur = cur->next;
    }
    return true;
}

bool unload(TrainCar* head, CarType type, int amount)
{
    //first check if it is possible
    int remaining = amount;
    //find the tail
    TrainCar* tail = head;
    while(tail->next)
        tail = tail->next;
    TrainCar* cur = tail;
    while(cur && remaining>0)
    {
        if(cur->type == type)
            remaining -= cur->load;
        cur = cur->prev;
    }
    if(remaining>0)
        return false;

    //now actually unload from the end of the train
    remaining = amount;
    cur = tail;
    while(cur && remaining>0)
    {
        if(cur->type == type)
        {
            remaining -= cur->load;
            if(remaining >= 0) //complete unload
                cur->load = 0;
            else //incomplete unload
                cur->load = -remaining;
        }
        cur = cur->prev;
    }
    return true;
}

void printCargoStats(const TrainCar* head)
{
    int totalLoad[CARGO_TYPE_COUNT+1] = {};
    int totalMaxLoad[CARGO_TYPE_COUNT+1] = {};
    int type[CARGO_TYPE_COUNT] = {}; 
    int nonZeroCargoTypes = 0;
    TrainCar* cur = head->next;
    while(cur)
    {
        //the following adds the cargo type to the end of the type list if it is not already there
        bool exists = false;
        for(int i=0; i<nonZeroCargoTypes; i++)
        {
            if(type[i] == cur->type)
            {
                exists = true;
                break;
            }
        }
        if(!exists)
        {
            type[nonZeroCargoTypes++] = cur->type;
        }

        //now update the stats
        totalLoad[cur->type] += cur->load;
        totalMaxLoad[cur->type] += cur->maxLoad;
        cur = cur->next;
    }

    const char enumToStringMapping[6][8] = {"HEAD", "OIL", "COAL", "WOOD", "STEEL", "SUGAR"};
    for(int i=0; i<nonZeroCargoTypes; i++)
    {
        cout << enumToStringMapping[type[i]] << ":" << totalLoad[type[i]] << "/" << totalMaxLoad[type[i]] << ((i!=nonZeroCargoTypes-1)?",":"");
    }
    cout << endl;
}

void divide(const TrainCar* head,  TrainCar* results[CARGO_TYPE_COUNT])
{
    //the following is probably not the most efficient solution, but it is rather simple to write and understand
    //we can probably move this to a helper function since we did something similar in the previous function
    int type[CARGO_TYPE_COUNT] = {}; 
    int nonZeroCargoTypes = 0;
    TrainCar* cur = head->next;
    while(cur)
    {
        //the following adds the cargo type to the end of the type list if it is not already there
        bool exists = false;
        for(int i=0; i<nonZeroCargoTypes; i++)
        {
            if(type[i] == cur->type)
            {
                exists = true;
                break;
            }
        }
        if(!exists)
        {
            type[nonZeroCargoTypes++] = cur->type;
        }
        cur = cur->next;
    }

    for(int i=0; i<CARGO_TYPE_COUNT; i++) //set all pointers to nullptr first
        results[i] = nullptr;
    
    for(int i=0; i<nonZeroCargoTypes; i++)
    {
        TrainCar* cur = head->next;
        while(cur)
        {
            if(cur->type == type[i])
            {
                if(!results[i]) //create the head if none exists yet
                    results[i] = createTrainHead();
                int carCount = getCarLength(results[i]);
                addCar(results[i], carCount, cur->type, cur->maxLoad);
                locateCar(results[i], carCount)->load = cur->load;
            }
            cur = cur->next;
        }
    }
}

//our own helper function used in optimizeForMaximumPossibleCargos
int getTotalCargo(const TrainCar* head)
{
    int total = 0;
    while((head=head->next))
        total += head->load;
    return total;
}

//our own helper function used in optimizeForMaximumPossibleCargos
TrainCar* arrayToTrain(const TrainCar* head, bool* array, int arraySize) //returns a new train given the boolean array
{
    TrainCar* newTrain = createTrainHead();
    for(int i=1;i<=arraySize;i++)
    {
        if(array[i-1])
        {
            const TrainCar* oldCar = locateCar(head, i);
            int length = getCarLength(newTrain);
            addCar(newTrain, length, oldCar->type, oldCar->maxLoad);
            locateCar(newTrain, length)->load = oldCar->load;
        }
    }
    return newTrain;
}

//our own helper function used in optimizeForMaximumPossibleCargos
void maximum(int upperBound, const TrainCar* head, bool* array, int curArraySize, int maxArraySize, int& maxCargo, bool* maxArray) //recursively generates all combinations of cars and keeps the best one
{
    if(curArraySize >= maxArraySize)
    {
        TrainCar* curTrain = arrayToTrain(head, array, maxArraySize); //note: actually we can just use a function to get the total cargo load given an array without creating the train
        int totalCargo = getTotalCargo(curTrain);
        deallocateTrain(curTrain);

        // if(totalCargo >= 84 && totalCargo <= upperBound) {cout << "!!!DEBUG: "; for(int i=0; i<maxArraySize; i++) cout << array[i] << ","; cout << endl;} //for debugging only

        if(totalCargo > maxCargo && totalCargo <= upperBound)
        {
            maxCargo = totalCargo;
            for(int i=0; i<maxArraySize; i++)
                maxArray[i] = array[i];
        }

        return;
    }

    array[curArraySize] = false;
    maximum(upperBound, head, array, curArraySize+1, maxArraySize, maxCargo, maxArray);
    array[curArraySize] = true;
    maximum(upperBound, head, array, curArraySize+1, maxArraySize, maxCargo, maxArray);
}

TrainCar* optimizeForMaximumPossibleCargos(const TrainCar* head, int upperBound)
{
    //note: this is definitely not the most efficient approach
    //for example, one can get the total cargo load of an imaginary train without actually dynamically creating it 
    //as to exactly how, well, it is left to those curious and motivated to try as an exercise ;)

    int maxArraySize = getCarLength(head) - 1;
    int maxCargo = 0;
    bool* array = new bool[maxArraySize];
    bool* maxArray = new bool[maxArraySize];
    maximum(upperBound, head, array, 0, maxArraySize, maxCargo, maxArray);
    TrainCar* result = arrayToTrain(head, maxArray, maxArraySize);
    delete [] array;
    delete [] maxArray;
    return result;
}

void deallocateTrain(TrainCar* head)
{
    while(head)
    {
        TrainCar* next = head->next;
        delete head;
        head = next;
    }
}
