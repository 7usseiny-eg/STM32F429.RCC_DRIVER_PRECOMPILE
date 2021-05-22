#include "RCC_CNFG.h"

void vRCC_SetSYSCLK(){
	
	#if SYSCLK == HSE
	SET_BIT(RCC_CR, 16);
		#if HSECLK == RC
		SET_BIT(RCC_CR, 18); //SETTING THE BYPASS TO 1 IF HSE IS USING RC
		CLEAR_BIT(RCC_CFGR, 0); // SETTING SYSCLK TO HSE
		CLEAR_BIT(RCC_CFGR, 1);
		#elif	HSECLK == CRYSTAL
		CLEAR_BIT(RCC_CR, 18); // SETTING THE BYPASS TO 0 IF HSE IS USING CRYSTAL
		CLEAR_BIT(RCC_CFGR, 0); // SETTING SYS CLOCK TO HSE
		CLEAR_BIT(RCC_CFGR, 1);
		#endif
	#elif SYSCLK == HSI
	SET_BIT(RCC_CR, 0);
	CLEAR_BIT(RCC_CFGR, 0);
	CLEAR_BIT(RCC_CFGR, 1);
	#else // PLL CLOCK
	//ENABLE PLL
	SET_BIT(RCC_CR, 24);
	/* SETTING Q VALUE */
	SET_BITS(RCC_PLLCFGR, QVALUE, 24); // SETS BITS 24 to 27 to a specific value, MAX VALUE IS 15 or 1 1 1 1
	/* SETTING N VALUE */
	SET_BITS(RCC_PLLCFGR, NVALUE, 6);
	/* SETTING P VALUE */
	SET_BITS(RCC_PLLCFGR, PVALUE, 16);
	/* SETTING M VALUE */
	SET_BITS(RCC_PLLCFGR, MVALUE, 0);
	//CHOOSING THE PLL SOURCE
		#if PLLCLK == HSE
		SET_BIT(RCC_PLLCFGR, 22);
		#else PLLCLK == HSI
		CLEAR_BIT(RCC_PLLCFGR, 22);
		#endif
	SET_BIT(RCC_CFGR, 1);
	CLEAR_BIT(RCC_CFGR, 0);
	#endif
	
	// PRESCALERS CONFIGURATION
	#if AHBPRESCALER == 1
	CLEAR_BIT(RCC_CFGR, 7);
	#elif AHBPRESCALER == 2
	SET_BIT(RCC_CFGR, 7);
	#elif AHBPRESCALER == 4
	SET_BIT(RCC_CFGR, 7);
	SET_BIT(RCC_CFGR, 4);
	#elif AHBPRESCALER == 8
	SET_BIT(RCC_CFGR, 7);
	SET_BIT(RCC_CFGR, 5);
	#elif AHBPRESCALER == 16
	SET_BIT(RCC_CFGR, 7);
	SET_BIT(RCC_CFGR, 5);
	SET_BIT(RCC_CFGR, 4);
	#elif AHBPRESCALER == 64
	SET_BIT(RCC_CFGR, 7);
	SET_BIT(RCC_CFGR, 6);
	#elif AHBPRESCALER == 128
	SET_BIT(RCC_CFGR, 7);
	SET_BIT(RCC_CFGR, 6);
	SET_BIT(RCC_CFGR, 4);
	#elif AHBPRESCALER == 256
	SET_BIT(RCC_CFGR, 7);
	SET_BIT(RCC_CFGR, 6);
	SET_BIT(RCC_CFGR, 5);
	#elif AHBPRESCALER == 512
	SET_BIT(RCC_CFGR, 7);
	SET_BIT(RCC_CFGR, 6);
	SET_BIT(RCC_CFGR, 5);
	SET_BIT(RCC_CFGR, 4);
	#endif
	
	#if APB1PRESCALER == 1
	CLEAR_BIT(RCC_CFGR, 12);
	#elif APB1PRESCALER == 2
	SET_BIT(RCC_CFGR, 12);
	#elif APB1PRESCALER == 4
	SET_BIT(RCC_CFGR, 12);
	SET_BIT(RCC_CFGR, 10);
	#elif APB1PRESCALER == 8
	SET_BIT(RCC_CFGR, 12);
	SET_BIT(RCC_CFGR, 11);
	#elif APB1PRESCALER == 16
	SET_BIT(RCC_CFGR, 12);
	SET_BIT(RCC_CFGR, 11);
	SET_BIT(RCC_CFGR, 10);
	#endif
	
	#if APB2PRESCALER == 1
	CLEAR_BIT(RCC_CFGR, 12);
	#elif APB2PRESCALER == 2
	SET_BIT(RCC_CFGR, 12);
	#elif APB2PRESCALER == 4
	SET_BIT(RCC_CFGR, 12);
	SET_BIT(RCC_CFGR, 10);
	#elif APB2PRESCALER == 8
	SET_BIT(RCC_CFGR, 12);
	SET_BIT(RCC_CFGR, 11);
	#elif APB2PRESCALER == 16
	SET_BIT(RCC_CFGR, 12);
	SET_BIT(RCC_CFGR, 11);
	SET_BIT(RCC_CFGR, 10);
	#endif
}
