#include "gd32vw55x.h"
#include "systick.h"

int main(void) {
    /* 1. Habilitar reloj de energía y Backup Domain (PC13) */
    rcu_periph_clock_enable(RCU_PMU);
    pmu_backup_write_enable();

    /* 2. Habilitar reloj para GPIOC */
    rcu_periph_clock_enable(RCU_GPIOC);

    /* 3. Configurar PC13 como Salida Push-Pull */
    gpio_mode_set(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_13);
    gpio_output_options_set(GPIOC, GPIO_OTYPE_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_13);

    /* 4. Configurar SysTick para el retardo en milisegundos */
    systick_config();

    while (1) {
        /* Encendido (500 ms = 0.5 segundos) */
        gpio_bit_set(GPIOC, GPIO_PIN_13);
        delay_1ms(500);

        /* Apagado (500 ms = 0.5 segundos) */
        gpio_bit_reset(GPIOC, GPIO_PIN_13);
        delay_1ms(500);
    }

    return 0;
}