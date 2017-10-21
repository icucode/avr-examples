# Make rules to build and upload arduino programs to target mmcu.

# Variables defining program, upload and target settings.
program_name  = blink
frequency_cpu = 16000000
tty_port      = /dev/ttyUSB0
baud_rate     = 57600         # Defined by arduino boot loader.
mmcu          = atmega328p    # http://nongnu.org/avr-libc/user-manual/index.html
part_no       = m328p         # avrdude -p ?

$(program_name).o:
			avr-gcc -DF_CPU=$(frequency_cpu) -mmcu=$(mmcu) -Os -c $(program_name).c

$(program_name).elf: $(program_name).o
			avr-gcc -DF_CPU=$(frequency_cpu) -mmcu=$(mmcu) -o $(program_name).elf $(program_name).o

$(program_name).hex: $(program_name).elf
			avr-objcopy -O ihex $(program_name).elf $(program_name).hex

deploy: $(program_name).hex
			avrdude -c arduino -p $(part_no) -U flash:w:$(program_name).hex:i -v -P $(tty_port) -b$(baud_rate) -D

clean:
			rm -f $(program_name).o $(program_name).elf $(program_name).hex