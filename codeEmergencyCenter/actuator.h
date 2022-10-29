#ifndef ACTUATOR_H
#define ACTUATOR_H

#include <emergencyservices.h>
#include <string>

class Actuator : public EmergencyServices
{
public:
    Actuator(std::string name);

    using EmergencyServices::execute;
    void execute();
};

#endif // ACTUATOR_H