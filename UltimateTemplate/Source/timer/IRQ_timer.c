/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_timer.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    timer.h
IRQ_timer.c gestisce gli interrupt generati dai timer hardware (Timer0, Timer1, Timer2, Timer3).
Ogni timer ha una Interrupt Service Routine (ISR) che viene eseguita automaticamente quando il timer raggiunge il valore di match configurato.
Questo file si occupa di gestire i comportamenti specifici da eseguire in corrispondenza di tali eventi.
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "LPC17xx.h"
#include "timer.h"
#include "../led/led.h"

/*
Ogni ISR ha lo stesso schema di base:

Controlla quale Match Register (MR) ha generato l�interrupt.
Esegue le azioni associate al Match Register corrispondente.
Resetta il flag di interrupt per consentire nuovi eventi.

Ogni timer ha 4 Match Register (MR0, MR1, MR2, MR3) che possono essere configurati per generare eventi a determinati intervalli.
*/


/******************************************************************************
** Function name:		Timer0_IRQHandler
**
** Descriptions:		Timer/Counter 0 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/

extern int next_power_pill_score;

extern unsigned char led_value;					/* defined in funct_led								*/
void TIMER0_IRQHandler (void)
{
	//LPC_TIM0->IR: Il registro di interrupt (Interrupt Register) indica quale MR ha generato l�interrupt:
	
	/* Match register 0 interrupt service routine */
	if (LPC_TIM0->IR & 01)
	{
		//code here
		// Aggiorna la posizione di Pac-Man
		pacman_update();
		
		LPC_TIM0->IR = 1;			/* clear interrupt flag */
	}
		/* Match register 1 interrupt service routine */
	  /* it should be possible to access to both interrupt requests in the same procedure*/
	if(LPC_TIM0->IR & 02)
  {
	
		LPC_TIM0->IR =  2 ;			/* clear interrupt flag */	
	}
	/* Match register 2 interrupt service routine */
  /* it should be possible to access to both interrupt requests in the same procedure*/
	if(LPC_TIM0->IR & 4)
  {
		
		LPC_TIM0->IR =  4 ;			/* clear interrupt flag */	
	}
		/* Match register 3 interrupt service routine */
  	/* it should be possible to access to both interrupt requests in the same procedure*/
	if(LPC_TIM0->IR & 8)
  {
	 
		LPC_TIM0->IR =  8 ;			/* clear interrupt flag */	
	}
  return;
}


/******************************************************************************
** Function name:		Timer1_IRQHandler
**
** Descriptions:		Timer/Counter 1 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
#include "labyrinth/labyrinth.h"
void TIMER1_IRQHandler (void)
{
  /* Match register 0 interrupt service routine */
	if (LPC_TIM1->IR & 01)
	{	//code here
		if(countdown > 0){
			countdown--;
			
		if (score >= next_power_pill_score && power_pills_generated < 6) {
				generate_power_pills();  // Genera una nuova Power Pill
				next_power_pill_score += 100; // Incrementa la soglia per la prossima Power Pill
		}
			
			// Aggiorna il display con il nuovo valore del timer
			display_timer();
		}
		
		LPC_TIM1->IR = 1;			/* clear interrupt flag */
	}
		/* Match register 1 interrupt service routine */
	  /* it should be possible to access to both interrupt requests in the same procedure*/
	if(LPC_TIM1->IR & 02)
  {
	
		LPC_TIM1->IR =  2 ;			/* clear interrupt flag */	
	}
	/* Match register 2 interrupt service routine */
  /* it should be possible to access to both interrupt requests in the same procedure*/
	if(LPC_TIM1->IR & 4)
  {
		
		LPC_TIM1->IR =  4 ;			/* clear interrupt flag */	
	}
		/* Match register 3 interrupt service routine */
  	/* it should be possible to access to both interrupt requests in the same procedure*/
	if(LPC_TIM1->IR & 8)
  {
	 
		LPC_TIM1->IR =  8 ;			/* clear interrupt flag */	
	}
  return;
}

/******************************************************************************
** Function name:		Timer2_IRQHandler
**
** Descriptions:		Timer/Counter 2 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
void TIMER2_IRQHandler (void)
{
  /* Match register 0 interrupt service routine */
	if (LPC_TIM2->IR & 01)
	{
		// Controlla se � il momento di generare le Power Pills
    /*if (countdown <= 50 && countdown > 20 && !power_pills_generated) {
				// Usa il tempo e lo score per una probabilit� casuale
        if ((LPC_TIM1->TC + score) % (50 - countdown + 1) == 0) { // Probabilit� crescente
            generate_power_pills();
        }
    }*/
		
		/*
		if (score >= next_power_pill_score && power_pills_generated < 6) {
				generate_power_pills();  // Genera una nuova Power Pill
				next_power_pill_score += 100; // Incrementa la soglia per la prossima Power Pill
		}
		*/
			
		LPC_TIM2->IR = 1;			/* clear interrupt flag */
	}
		/* Match register 1 interrupt service routine */
	  /* it should be possible to access to both interrupt requests in the same procedure*/
	if(LPC_TIM2->IR & 02)
  {
	
		LPC_TIM2->IR =  2 ;			/* clear interrupt flag */	
	}
	/* Match register 2 interrupt service routine */
  /* it should be possible to access to both interrupt requests in the same procedure*/
	if(LPC_TIM2->IR & 4)
  {
		
		LPC_TIM2->IR =  4 ;			/* clear interrupt flag */	
	}
		/* Match register 3 interrupt service routine */
  	/* it should be possible to access to both interrupt requests in the same procedure*/
	if(LPC_TIM2->IR & 8)
  {
	 
		LPC_TIM2->IR =  8 ;			/* clear interrupt flag */	
	}
  return;
}

/******************************************************************************
** Function name:		Timer3_IRQHandler
**
** Descriptions:		Timer/Counter 3 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
void TIMER3_IRQHandler (void)
{
  /* Match register 0 interrupt service routine */
	if (LPC_TIM3->IR & 01)
	{
		
		LPC_TIM3->IR = 1;			/* clear interrupt flag */
	}
		/* Match register 1 interrupt service routine */
	  /* it should be possible to access to both interrupt requests in the same procedure*/
	if(LPC_TIM3->IR & 02)
  {
	
		LPC_TIM3->IR =  2 ;			/* clear interrupt flag */	
	}
	/* Match register 2 interrupt service routine */
  /* it should be possible to access to both interrupt requests in the same procedure*/
	if(LPC_TIM3->IR & 4)
  {
		
		LPC_TIM3->IR =  4 ;			/* clear interrupt flag */	
	}
		/* Match register 3 interrupt service routine */
  	/* it should be possible to access to both interrupt requests in the same procedure*/
	if(LPC_TIM3->IR & 8)
  {
	 
		LPC_TIM3->IR =  8 ;			/* clear interrupt flag */	
	}
  return;
}



/******************************************************************************
**                            End Of File
******************************************************************************/
