TARGET = PSPGL-Moehammered
OBJS = Main.o Display.o Triangle.o Cube.o Controller.o Vector.o Texture.o SaveGameIO.o

CFLAGS = -O2 -G0 -Wall
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

INCDIR = C:\pspdev\psp\Projects\PSPPractice\PSPPractice

PSPBIN = $(PSPSDK)/../bin
CFLAGS += -I$(PSPSDK)/../include  -fsingle-precision-constant -g -Wall -O2 
LIBS += -lglut -lGLU -lGL -lm -lc -lpsputility -lpspdebug -lpspge -lpspdisplay -lpspctrl -lpspsdk -lpspvfpu -lpsplibc -lpspuser -lpspkernel -lpsprtc -lpsppower -lstdc++ -lpng -lz -lm
LDFLAGS += -DMODULE_NAME="lesson1" psp-setup.c


EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = MineCraft-PSP_by_Mouhamad&David
PSP_EBOOT_ICON = ICON0.png
PSP_EBOOT_PIC1 = PIC1.png


PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak