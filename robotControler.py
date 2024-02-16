import pygame, sys

pygame.init()
size = [1000,600]
screen = pygame.display.set_mode(size)
clock = pygame.time.Clock();

pygame.joystick.init()
joystick = pygame.joystick.Joystick(0)
#print(pygame.joystick.init())

axes = [0,0,0,0,0,0,0]
buttons=[False, False, False, False, False, False]

slider = pygame.Surface((30,50))
slider.fill([255,255,100])

aButton1=pygame.Surface((75,75), flags=pygame.SRCALPHA)
pygame.draw.circle(aButton1, (200, 0, 0), [75/2, 75/2], 75/2)
aButton2=pygame.Surface((75,75), flags=pygame.SRCALPHA)
pygame.draw.circle(aButton2, (255, 0, 0), [75/2, 75/2], 75/2)

tButton1=pygame.Surface((50,50), flags=pygame.SRCALPHA)
pygame.draw.circle(tButton1, (150, 150, 150), [25, 25], 25)
pygame.draw.circle(tButton1, (0, 0, 0), [25, 25], 15,2)
tButton2=pygame.Surface((50,50), flags=pygame.SRCALPHA)
pygame.draw.circle(tButton2, (150, 150, 150), [25, 25], 25)
pygame.draw.circle(tButton2, (125, 125, 125), [25, 25], 15)
pygame.draw.circle(tButton2, (0, 0, 0), [25, 25], 15,2)

while True:
    #get events
    for event in pygame.event.get():
        #print(event) #why you no?
        if event.type==pygame.QUIT:
            sys.exit()
            
        if event.type == pygame.JOYAXISMOTION:
            axes[event.axis] = event.value+1
        if event.type == pygame.JOYBUTTONDOWN:
            buttons[event.button]=True
        if event.type == pygame.JOYBUTTONUP:
            buttons[event.button]=False
    
    print(axes, buttons)
    
    
    
    
    screen.fill([0,0,255])

    screen.blit(slider, [850, 400])
    screen.blit(aButton1, [865-75/2, 100])
    screen.blit(slider, [650, 400])
    screen.blit(aButton1, [665-75/2, 100])
    screen.blit(slider, [450, 400])
    screen.blit(aButton1, [465-75/2, 100])
    screen.blit(slider, [250, 400])
    screen.blit(aButton2, [265-75/2, 100])
    
    screen.blit(tButton1, [75, 200])
    screen.blit(tButton2, [75, 300])
    
    
    
    #print(clock.get_fps())
    pygame.display.flip()
    clock.tick(100)
