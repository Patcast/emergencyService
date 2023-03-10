#ifndef COMPONENT_H
#define COMPONENT_H
#include <string>
#include <QVector>


enum class sorter{ id, vendor, location};

class Component
{
private:
    int id;
    std::string description;

public:
    Component(std::string_view description);
    int getId() const;
    std::string_view getDescription() const;
    //std::vector<std::shared_ptr<Component>> getChildren(sorter sortement);
    void printSensorsSorted(sorter sortement);
    static bool compareIds(std::shared_ptr<Component> c1, std::shared_ptr<Component> c2);
    static bool compareVendors(std::shared_ptr<Component> c1, std::shared_ptr<Component> c2);
    static bool compareLocations(std::shared_ptr<Component> c1, std::shared_ptr<Component> c2);
    static void sort(std::vector<std::shared_ptr<Component>> &components, sorter sortement);
    Component& operator++(); //prefix
    Component& operator--(); //prefix
    Component& operator<<(Component &s); //prefix
    // Virtuals
    virtual void printInfo() const;
    virtual void setLocation(const std::string_view &newLocation);
    virtual const std::string & getLocation() const;
    virtual int addNewComponent(std::shared_ptr<Component> newChild) = 0;
    virtual int removeComponent(std::shared_ptr<Component> unWantedChild) = 0;
    virtual int testSensor() = 0;
    virtual int activateSensor()=0;
    virtual int deActivateSensor() = 0;
    virtual int getChildren(std::vector<std::shared_ptr<Component>> &sensors)  const = 0;

};

#endif // COMPONENT_H
