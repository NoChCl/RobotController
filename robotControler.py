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

n4Button1=pygame.Surface((75,75), flags=pygame.SRCALPHA)
pygame.draw.circle(n4Button1, (150, 0, 0), [75/2, 75/2], 75/2)
n4Button2=pygame.Surface((75,75), flags=pygame.SRCALPHA)
pygame.draw.circle(n4Button2, (255, 0, 0), [75/2, 75/2], 75/2)

n3Button1=pygame.Surface((75,75), flags=pygame.SRCALPHA)
pygame.draw.circle(n3Button1, (0, 100, 120), [75/2, 75/2], 75/2)
n3Button2=pygame.Surface((75,75), flags=pygame.SRCALPHA)
pygame.draw.circle(n3Button2, (0, 200, 255), [75/2, 75/2], 75/2)

n2Button1=pygame.Surface((75,75), flags=pygame.SRCALPHA)
pygame.draw.circle(n2Button1, (0, 100, 0), [75/2, 75/2], 75/2)
n2Button2=pygame.Surface((75,75), flags=pygame.SRCALPHA)
pygame.draw.circle(n2Button2, (0, 255, 0), [75/2, 75/2], 75/2)

n1Button1=pygame.Surface((75,75), flags=pygame.SRCALPHA)
pygame.draw.circle(n1Button1, (100,100,100), [75/2, 75/2], 75/2)
n1Button2=pygame.Surface((75,75), flags=pygame.SRCALPHA)
pygame.draw.circle(n1Button2, (255,255,0), [75/2, 75/2], 75/2)

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
            axes[event.axis] = (int((event.value+1)*100))
        if event.type == pygame.JOYBUTTONDOWN:
            buttons[event.button]=True
        if event.type == pygame.JOYBUTTONUP:
            buttons[event.button]=False

        
    
    
    
    print(axes, buttons)
    
    
    if buttons[0]:
        n1Button = n1Button2
    else:
        n1Button=n1Button1
    
    if buttons[1]:
        n2Button = n2Button2
    else:
        n2Button=n2Button1
    
    if buttons[2]:
        n3Button = n3Button2
    else:
        n3Button=n3Button1
    
    if buttons[3]:
        n4Button = n4Button2
    else:
        n4Button=n4Button1
    
    screen.fill([0,0,255])

    screen.blit(slider, [850, 400-axes[6]])
    screen.blit(n4Button, [865-75/2, 100])
    screen.blit(slider, [650, 400-axes[2]])
    screen.blit(n3Button, [665-75/2, 100])
    screen.blit(slider, [450, 400-axes[5]])
    screen.blit(n2Button, [465-75/2, 100])
    screen.blit(slider, [250, 400-axes[0]])
    screen.blit(n1Button, [265-75/2, 100])
    
    screen.blit(tButton1, [75, 200])
    screen.blit(tButton2, [75, 300])
    
    
    
    #print(clock.get_fps())
    pygame.display.flip()
    clock.tick(100)
