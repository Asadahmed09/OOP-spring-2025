#include <iostream>
using namespace std;

class SmartDevice 
{
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void getStatus() = 0;
};

class LightBulb : public SmartDevice 
{
private:
    bool isOn;
    int brightness;

public:
    LightBulb() 
    {
        isOn = false;
        brightness = 0;
    }

    void turnOn() 
    {
        isOn = true;
        brightness = 75;
        cout << "LightBulb turned ON with brightness " << brightness << "%" << endl;
    }

    void turnOff() 
    {
        isOn = false;
        brightness = 0;
        cout << "LightBulb turned OFF." << endl;
    }

    void getStatus() 
    {
        if (isOn) 
        {
            cout << "LightBulb is ON. Brightness: " << brightness << "%" << endl;
        } 
        else 
        {
            cout << "LightBulb is OFF. Brightness: " << brightness << "%" << endl;
        }
    }
};

class Thermostat : public SmartDevice 
{
private:
    bool isOn;
    double temperature;

public:
    Thermostat() 
    {
        isOn = false;
        temperature = 0.0;
    }

    void turnOn() 
    {
        isOn = true;
        temperature = 22.5;
        cout << "Thermostat turned ON. Temperature set to " << temperature << "°C" << endl;
    }

    void turnOff() 
    {
        isOn = false;
        temperature = 0.0;
        cout << "Thermostat turned OFF." << endl;
    }

    void getStatus() 
    {
        if (isOn) 
        {
            cout << "Thermostat is ON. Temperature: " << temperature << "°C" << endl;
        } 
        else 
        {
            cout << "Thermostat is OFF. Temperature: " << temperature << "°C" << endl;
        }
    }
};

int main() 
{
    SmartDevice* d1 = new LightBulb();
    SmartDevice* d2 = new Thermostat();

    d1->turnOn();
    d1->getStatus();
    d1->turnOff();
    d1->getStatus();

    cout << endl;

    d2->turnOn();
    d2->getStatus();
    d2->turnOff();
    d2->getStatus();

    delete d1;
    delete d2;

    return 0;
}