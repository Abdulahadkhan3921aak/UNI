#include <iostream>
#include <vector>
#include <random>

using namespace std;

class Vehicle
{
protected:
    string registrationNumber;
    string brand;
    double maxSpeed;

public:
    Vehicle()
    {
    }
    Vehicle(string regNum, string brand, double maxSpeed)
    {
        this->registrationNumber = regNum;
        this->brand = brand;
        this->maxSpeed = maxSpeed;
    }

    string getRegistrationNumber()
    {
        return registrationNumber;
    }

    string getBrand()
    {
        return brand;
    }

    double getMaxSpeed()
    {
        return maxSpeed;
    }

    void setRegistrationNumber(string regNum)
    {
        registrationNumber = regNum;
    }

    void setBrand(string vehicleBrand)
    {
        brand = vehicleBrand;
    }

    void setMaxSpeed(double speed)
    {
        maxSpeed = speed;
    }

    virtual void displayInfo()  = 0;

    bool operator==(Vehicle &other) 
    {
        return this->registrationNumber == other.getRegistrationNumber();
    }
};

class Car : public Vehicle
{
private:
    int numDoors;

public:
    Car()
    {
    }
    Car(string regNum, string brand, double maxSpeed, int doors)
    {
        this->registrationNumber = regNum;
        this->brand = brand;
        this->maxSpeed = maxSpeed;
        this->numDoors = doors;
    }

    int getNumDoors() 
    {
        return numDoors;
    }

    void setNumDoors(int doors)
    {
        numDoors = doors;
    }

    void displayInfo()  override
    {
        cout << "Car Information:\n";
        cout << "Registration Number: " << getRegistrationNumber() << "\n";
        cout << "Brand: " << getBrand() << "\n";
        cout << "Max Speed: " << getMaxSpeed() << " km/h\n";
        cout << "Number of Doors: " << numDoors << "\n";
    }
};

class Motorcycle : public Vehicle
{
private:
    string type;

public:
    Motorcycle()
    {
    }
    Motorcycle(string regNum, string brand, double maxSpeed, string type)
    {
        this->registrationNumber = regNum;
        this->brand = brand;
        this->maxSpeed = maxSpeed;
        this->type = type;
    }

    string getType() 
    {
        return type;
    }

    void setType( string &vehicleType)
    {
        type = vehicleType;
    }

    void displayInfo()  override
    {
        cout << "Motorcycle Information:\n";
        cout << "Registration Number: " << getRegistrationNumber() << "\n";
        cout << "Brand: " << getBrand() << "\n";
        cout << "Max Speed: " << getMaxSpeed() << " km/h\n";
        cout << "Type: " << type << "\n";
    }
};

class Truck : public Vehicle
{
private:
    double maxWeight;

public:
    Truck()
    {
    }
    Truck(string regNum, string brand, double maxSpeed, double weight)
    {
        this->registrationNumber = regNum;
        this->brand = brand;
        this->maxSpeed = maxSpeed;
        this->maxWeight = weight;
    }

    double getMaxWeight() 
    {
        return maxWeight;
    }

    void setMaxWeight(double weight)
    {
        maxWeight = weight;
    }

    void displayInfo()  override
    {
        cout << "Truck Information:\n";
        cout << "Registration Number: " << getRegistrationNumber() << "\n";
        cout << "Brand: " << getBrand() << "\n";
        cout << "Max Speed: " << getMaxSpeed() << " km/h\n";
        cout << "Max Weight: " << maxWeight << " kg\n";
    }
};

class TrafficControlCenter
{
private:
    vector<Vehicle *> vehicles;

public:
    void registerVehicle()
    {
        string vehicleType;
        cout << "Enter the type of vehicle (Car, Motorcycle, Truck): ";
        cin >> vehicleType;

        string regNum, brand;
        double maxSpeed;


        cout << "Enter the registration number: ";
        cin >> regNum;
        cout << "Enter the brand: ";
        cin >> brand;
        cout << "Enter the maximum speed: ";
        cin >> maxSpeed;

        if (vehicleType == "Car" || vehicleType == "car")
        {
            int numDoors;
            cout << "Enter the number of doors: ";
            cin >> numDoors;
            vehicles.push_back(new Car(regNum, brand, maxSpeed, numDoors));
        }
        else if (vehicleType == "Motorcycle" || vehicleType == "motorcycle")
        {
            string type;
            cout << "Enter the type of motorcycle: ";
            cin >> type;
            vehicles.push_back(new Motorcycle(regNum, brand, maxSpeed, type));
        }
        else if (vehicleType == "Truck" || vehicleType == "truck")
        {
            double maxWeight;
            cout << "Enter the maximum weight: ";
            cin >> maxWeight;
            vehicles.push_back(new Truck(regNum, brand, maxSpeed, maxWeight));
        }
        else
        {
            cout << "Invalid vehicle type.\n";
        }
    }

    void monitorTrafficSpeed() 
    {
        cout << "Traffic Speed Monitoring:\n";
        for ( auto &vehicle : vehicles)
        {
            cout << "Vehicle: " << vehicle->getRegistrationNumber()
                 << ", Max Speed: " << vehicle->getMaxSpeed() << " km/h\n";
        }
        cout << "Traffic speed monitored.\n";
    }

    void detectViolations() 
    {
        cout << "Violation Detection:\n";
        for ( auto &vehicle : vehicles)
        {
            if (vehicle->getMaxSpeed() > 120)
            {
                cout << "\tViolation Detected: Vehicle " << vehicle->getRegistrationNumber()
                     << " exceeded the speed limit.\n";
            }
        }
        cout << "Violation detection completed.\n";
    }
};

double generateRandomSpeedLimit()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(60, 120);
    return dis(gen);
}

double generateRandomMaxSpeed(double speedLimit)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, static_cast<int>(speedLimit));
    return dis(gen);
}

int main()
{
    TrafficControlCenter controlCenter;

    int choice;
    do
    {
        system("cls");
        cout << "\nTraffic Control Center Menu:\n";
        cout << "1. Register a new vehicle\n";
        cout << "2. Monitor traffic speed\n";
        cout << "3. Detect violations\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            controlCenter.registerVehicle();
            break;
        case 2:
            controlCenter.monitorTrafficSpeed();
            break;
        case 3:
            controlCenter.detectViolations();
            break;
        case 4:
            cout << "Exiting ......." << endl;
            break;
        default:
            cout << "Invalid Choics" << endl;
        }
        cout << "\n\nPress Enter to Continue .. " << endl;
        cin.ignore();
        cin.ignore();
    } while (choice != 4);

    return 0;
}
