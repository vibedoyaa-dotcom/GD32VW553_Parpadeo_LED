#include "gd32vw55x_it.h"
#include "main.h"
#include "systick.h"

/*!
    \brief      core private timer handle function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void eclic_mtip_handler(void)
{
    ECLIC_ClearPendingIRQ(CLIC_INT_TMR);
    delay_decrement();
}