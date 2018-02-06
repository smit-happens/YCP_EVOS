/**  Display controller class
 *
 * #include "GlcdController.hpp"
 * Created 1-5-17 By: Smitty
 *
 * A longer description.
 */

#ifndef GLCDCONTROLLER_HPP
#define GLCDCONTROLLER_HPP

#include "../BaseController/BaseController.hpp"
#include "../../Model/Glcd/Glcd.hpp"



class GlcdController
{
public:
    GlcdController();
    ~GlcdController(void);

    void init(void);
    void poll(void);
    void shutdown(void);    //TODO: implement
    /**  
     * Drafting up possible functions
     * 
     * 
     */
private:
    Glcd* glcdModel;


};


#endif  //GLCDCONTROLLER_HPP
