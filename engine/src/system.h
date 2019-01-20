#ifndef SYSTEM_H
#define SYSTEM_H


namespace sap
{
    class System
    {
        public:
            System()  = default;
            ~System() = default;

            virtual void update() = 0;
    };
}




#endif  // SYSTEM_H