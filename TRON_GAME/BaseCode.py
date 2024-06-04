from turtle import *
from freegames import vector
from PIL import Image
image = Image.open("Space.png")
image.save("Space.gif")
screen = Screen()
screen.setup(width=690, height=500)
screen.bgcolor("black")

screen.bgpic("Space.gif")
screen.addshape("Motor_blue_right.gif")
screen.addshape("Motor_blue_up.gif")
screen.addshape("Motor_blue_down.gif")
screen.addshape("Motor_blue_left.gif")
screen.addshape("Motor_yellow_right.gif")
screen.addshape("Motor_yellow_up.gif")
screen.addshape("Motor_yellow_down.gif")
screen.addshape("Motor_yellow_left.gif")
p1xy = vector(-100, 0)
p1aim = vector(4, 0)
p1body = set()

p2xy = vector(100, 0)
p2aim = vector(-4, 0)
p2body = set()

Motor1 = Turtle()
Motor1.shape("Motor_yellow_right.gif")
Motor1.penup()
Motor1.goto(p1xy.x, p1xy.y)

Motor2 = Turtle()
Motor2.shape("Motor_blue_left.gif")
Motor2.penup()
Motor2.goto(p2xy.x, p2xy.y)

def display_winner(winner):
    penup()
    if winner == "yellow":
       goto(-170, 200)
       color('yellow')
       write(f'WIN!', align='center', font=('Arial', 15, 'bold'))
    elif winner == "blue":
       goto(+180, 200)
       color('light blue')
       write(f'WIN!', align='center', font=('Arial', 15, 'bold'))
    done()

def inside(head):
    return -325 < head.x < 325 and -222 < head.y < 175

counter = 0
def change_motor_shape_a():
    global counter
    if counter == 0:
        Motor1.shape("Motor_yellow_up.gif")
        counter += 1
    elif counter == 1:
        Motor1.shape("Motor_yellow_left.gif")
        counter += 1
    elif counter == 2:
        Motor1.shape("Motor_yellow_down.gif")
        counter += 1
    elif counter == 3:
        Motor1.shape("Motor_yellow_right.gif")
        counter = 0
def change_motor_shape_d():
    global counter
    if counter == 3:
        Motor1.shape("Motor_yellow_left.gif")
        counter -= 1
    elif counter == 2:
        Motor1.shape("Motor_yellow_up.gif")
        counter -= 1
    elif counter == 1:
        Motor1.shape("Motor_yellow_right.gif")
        counter -= 1
    elif counter == 0:
        Motor1.shape("Motor_yellow_down.gif")
        counter = 3

counter2 = 0
def change_motor_shape_left():
    global counter2
    if counter2 == 0:
        Motor2.shape("Motor_blue_down.gif")
        counter2 += 1
    elif counter2 == 1:
        Motor2.shape("Motor_blue_right.gif")
        counter2 += 1
    elif counter2 == 2:
        Motor2.shape("Motor_blue_up.gif")
        counter2 += 1
    elif counter2 == 3:
        Motor2.shape("Motor_blue_left.gif")
        counter2 = 0

def change_motor_shape_right():
    global counter2
    if counter2 == 3:
        Motor2.shape("Motor_blue_right.gif")
        counter2 -= 1
    elif counter2 == 2:
        Motor2.shape("Motor_blue_down.gif")
        counter2 -= 1
    elif counter2 == 1:
        Motor2.shape("Motor_blue_left.gif")
        counter2 -= 1
    elif counter2 == 0:
        Motor2.shape("Motor_blue_up.gif")
        counter2 = 3
def draw():
    global p1aim, p2aim , counter 

    p1xy.move(p1aim)
    p1head = p1xy.copy()

    p2xy.move(p2aim)
    p2head = p2xy.copy()

    if not inside(p1head) or p1head  in p2body or p1head in p1body:
        display_winner("blue")
        return

    if not inside(p2head) or p2head  in p1body or p2head in p2body :
        display_winner("yellow")
        return
    
    p1body.add(p1head)
    p2body.add(p2head)
    
    penup()
    color('yellow')
    goto(p1xy.x, p1xy.y)
    pendown()
    dot(6)
    
    penup()
    color('blue')
    goto(p2xy.x, p2xy.y)
    pendown()
    dot(6)
     
    if counter == 0 :
     Motor1.goto(p1xy.x + 12 , p1xy.y - 8)
    elif counter == 1 :
     Motor1.goto(p1xy.x + 8 , p1xy.y + 12)
    elif counter == 2 :
     Motor1.goto(p1xy.x - 12 , p1xy.y + 8)
    elif counter == 3 :
     Motor1.goto(p1xy.x - 8 , p1xy.y - 12)
    
    if counter2 == 0 :
     Motor2.goto(p2xy.x - 12, p2xy.y + 8)
    elif counter2 == 1 :
     Motor2.goto(p2xy.x - 8, p2xy.y - 12)
    elif counter2 == 2 :
     Motor2.goto(p2xy.x + 12, p2xy.y - 8)
    elif counter2 == 3 :
     Motor2.goto(p2xy.x + 8, p2xy.y + 12)
    
    update()
    ontimer(draw, 50)
hideturtle()
tracer(False)
listen()

onkey(lambda: (p1aim.rotate(90), change_motor_shape_a()), 'a' or 'A')
onkey(lambda: (p1aim.rotate(-90), change_motor_shape_d()), 'd' or 'D')
onkey(lambda: (p2aim.rotate(90), change_motor_shape_left()), 'Left')
onkey(lambda: (p2aim.rotate(-90),change_motor_shape_right()), 'Right')

draw()
done()
