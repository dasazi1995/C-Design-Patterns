#include <iostream>
#include <vector>
using namespace std;
class Packing
{
public:
    virtual string pack() = 0;
};

class Item
{
public:
    virtual string name() = 0;
    virtual Packing* packing() = 0;
    virtual float price() = 0;
};

class Wrapper:public Packing{
    virtual string pack() override
    {
        return"Wrapper";
    }
};
class Bottle:public Packing{
    virtual string pack() override
    {
        return"Bottle";
    }
};
class Burger:public Item
{
    virtual Packing* packing() override
    {
        return new Wrapper();
    }
};


class ColdDrink:public Item
{
    virtual Packing* packing() override
    {
        return new Bottle();
    }
};
class VegBurger:public Burger{
    virtual float price() override
    {
        return 25.0f;
    }
    virtual string name() override
    {
        return "veg Burger";
    }
};
class Coke:public ColdDrink
{
    virtual float price() override
    {
        return 35.0f;
    }
    virtual string name() override
    {
        return "coke";
    }
};

class Meal{
private:
    vector<Item*> list;
public:
    void addItem(Item* obj)
    {
        list.push_back(obj);
    }
    float getCost(void)
    {
        float sum = 0;
        vector<Item*>::iterator iter;
            for(iter = list.begin();iter!=list.end();iter++)
            {
                sum += (*iter)->price();
            }
        return sum;
    }
    void showItems(void)
    {
        vector<Item*>::iterator iter;
        for(iter = list.begin();iter!=list.end();iter++)
        {
            cout<< (*iter)->name()<<endl;
            Packing* a = (*iter)->packing();
            cout<<a->pack()<<endl;
            cout<<(*iter)->price()<<endl;
        }

    }
};

int main(void)
{
    Meal*a = new Meal();
    a->addItem(new VegBurger());
    a->addItem(new Coke());
    a->showItems();
}