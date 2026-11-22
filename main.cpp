#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

class Vehicle {
protected:
    std::string registration;
    double dailyRate;
    bool rented = false;
public:
    Vehicle(std::string r, double rate)
        : registration(std::move(r)), dailyRate(rate) {}
    virtual double charge(int days) const = 0;
    bool rent() {
        if (rented) return false;
        rented = true;
        return true;
    }
    double returnVehicle(int lateDays, double feePerDay) {
        if (!rented) return 0.0;
        rented = false;
        return lateDays > 0 ? lateDays * feePerDay : 0.0;
    }
    virtual void display() const {
        std::cout << registration << " rate=" << dailyRate
                  << " rented=" << rented << '\n';
    }
    virtual ~Vehicle() = default;
};

class Bicycle : public Vehicle {
public:
    using Vehicle::Vehicle;
    double charge(int days) const override { return dailyRate * days; }
};

class MotorVehicle : public Vehicle {
protected:
    double fuelOrChargeLevel;
    std::string serviceDueDate;
    MotorVehicle(std::string r, double rate, double level, std::string due)
        : Vehicle(std::move(r), rate), fuelOrChargeLevel(level),
          serviceDueDate(std::move(due)) {}
};

class TwoWheeler : public MotorVehicle {
public:
    TwoWheeler(std::string r, double rate, double level, std::string due)
        : MotorVehicle(std::move(r), rate, level, std::move(due)) {}
    double charge(int days) const override { return dailyRate * days; }
};

class Car : public MotorVehicle {
protected:
    int seats;
public:
    Car(std::string r, double rate, double level, std::string due, int s)
        : MotorVehicle(std::move(r), rate, level, std::move(due)), seats(s) {}
    double charge(int days) const override { return dailyRate * days; }
};

class ElectricCar : public Car {
    double batteryCapacity;
    double pricePerKWh;
public:
    ElectricCar(std::string r, double rate, double level, std::string due,
                int s, double capacity, double kwhPrice)
        : Car(std::move(r), rate, level, std::move(due), s),
          batteryCapacity(capacity), pricePerKWh(kwhPrice) {}
    double charge(int days) const override {
        return dailyRate * days + batteryCapacity * pricePerKWh;
    }
};

class ElectricBus : public Vehicle {
    int seats;
public:
    ElectricBus(std::string r, double rate, int s)
        : Vehicle(std::move(r), rate), seats(s) {}
    double charge(int days) const override { return dailyRate * days; }
};

int main() {
    std::vector<std::unique_ptr<Vehicle>> fleet;
    fleet.push_back(std::make_unique<Bicycle>("BI-01", 100));
    fleet.push_back(std::make_unique<TwoWheeler>("TW-01", 250, 80, "2026-12-01"));
    fleet.push_back(std::make_unique<Car>("CA-01", 1200, 70, "2026-12-05", 5));
    fleet.push_back(std::make_unique<ElectricCar>("EV-01", 1500, 90,
                                                  "2026-12-10", 5, 60, 8.0));
    fleet.push_back(std::make_unique<ElectricBus>("EB-01", 3000, 30));

    for (auto& v : fleet) {
        std::cout << "Charge: " << v->charge(2) << '\n';
        std::cout << "Rented: " << v->rent() << '\n';
        std::cout << "Late fee: " << v->returnVehicle(1, 100) << '\n';
        v->display();
    }
}
