/**  DashController manages all the buttons and forms of user feedback/input to the EV
 *
 * #include "DashController.hpp"
 * Created 1-17-17 By: Smitty
 *
 * A longer description.
 */

#ifndef DASHCONTROLLER_HPP
#define DASHCONTROLLER_HPP

#include "../../Model/Light/Light.hpp"
#include "../../Model/Button/Button.hpp"


class DashController
{
public:
    DashController();
    ~DashController(void);

    void init(void);
    void poll(void);
    void shutdown(void);    //TODO: implement

    /**  
     * Drafting up possible functions
     * 
     * 
     */
private:
/*
    //all the buttons need to be implemented
    Button* shutdownBtn;
*/
};


#endif  //DASHCONTROLLER_HPP
