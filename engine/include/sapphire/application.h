#ifndef APPLICATION_H
#define APPLICATION_H


namespace sap
{
    class Application
    {
        public:
            Application()  = default;
            ~Application() = default;

            virtual bool init()     = 0;
            virtual void shutDown() = 0;
            virtual void run()      = 0;
            virtual void onUpdate() = 0;
    };
}


#endif  // APPLICATION_H