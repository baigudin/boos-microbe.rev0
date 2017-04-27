/** 
 * The operating system main class.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#include "boos.main.h" 
#include "boos.driver.processor.h"

/**
 * Initializes the operating system.
 * 
 * @return error code or else zero if no errors have been occurred.
 */
static int8 systemInit()
{
  int8 error;
  // Stage 1 
  error = processorInit();
  if(error != BOOS_OK) return error;      
  // Stage complete
  return userMain();
}

/**
 * The main function.
 * 
 * The method should be called after default boot initialization, and
 * the following tasks must be:
 * 1. Stack has been set.
 * 2. CPU registers have been set.
 * 3. Run-time initialization has been completed.
 * 4. Global variables have been set.
 * 5. Global constructors have been �alled.
 * 
 * @return error code or zero.
 */   
int main()
{
  return systemInit();
}
