/*
	API For accessing embedded systems functionality
*/

// XXX: Can this be relied on? (My sense is no, thus we'll need some "haxint.h")
#inlcude <stdint.h>

// Analog inputs 
//  includes on-robot sensors and remote inputs
// XXX: uint8_t could be changed to some enum type.
analog_t analog_get(uint8_t input_num);

// Digital I/O
void digital_set(uint8_t output_num);
BOOL digital_get(uint8_t input_num);

// Interupts
//  Could also give a bit less abstraction than this. Something like calling a
//  specific funtion for each interupt, and looking for them to enable said
//  interupt
//
//  Also, some interupts may need more config than on/off.
typedef void(*)(void) isr;
reg_isr(uint8_t interrupt_num, isr handler);
enable_interupt(uint8_t inter_num);
disable_interupt(uint8_t inter_num);


// Motors
//  We should define some type of range for all motors, and then convert for
//  motors than need different values.
typedef int8_t motor_speed_t;
enum {
	MOTOR_MAX=127,
	MOTOR_MIN=-127
};
void motor_set(uint8_t motor_num, motor_speed_t new_speed);	

// Servos
//  Same thing as motors on pic. May not be elsewhere.
typedef int8_t servo_setpoint_t;
enum {
	SERVO_MAX=127,
	SERVO_MIN=-127
};
void servo_set(uint8_t servo_num, servo_setpoint_t new_setpoint);

// Stream I/O (something for stdin/stdout)
//  Shall we use standard io or nix it? (I'm all for avoiding format strings
//  chewing up memory)
void puth(uint16_t hex);
void puts(const char *c);
//getc?
