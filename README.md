# TerminalTrig
Displays trig functions in ASCII form in the terminal with a gradient and varying magnitudes, using C.

## To Compile

```sh
gcc -o terminal_trig terminal_trig.c
```

## Documentation

Let's start of by saying I know the code could be better.

In it's current state, there are two main functions within the program; `print_fx()` and `print_fy()`, which respectively print f(x) and f(y) respectively to the terminal screen in 
ASCII code (or rather, the inequality region below f(x) or f(y)). Both of these utilise the same `f()` function declared earlier, which in this case is `sin(x)`, multiplied by a 
constant in order to better fit the screen.

### `factorial()`

>A rudimentary definition of a factorial function.

I only created this to see what factorial would look like graphed in ASCII. Didn't work out so well.

### `f()`

> Defines the *mathematical* function you want to apply to $x$ or $y$

In this case, the equation is $sin(x)$, multiplied by some constants in order to scale to an appropriate size to fit the screen.

### `print_fx()`

> Uses `f()` as $f(x)$, and thus prints $f(x)$ in the terminal.

Can't really be bothered to explain what's going on exactly right now, you'll probably be able to work it out anyway. In essence, it:
- Iterates through the specified width and height values, where $x$ values are columns and $y$ values are rows
- Prints an lighter or darker ASCII character based on the inequality of $y<=f(x)$, creating a contrast between sides of the equation
- Can optionally leaves spaces on the exact line of the equation, to outline where it is, though due to the limited precision of ASCII characters, this only works so well
- Prints a gradient of ASCII characters based on the current point's $(x, y)$ coordinates
- and randomises the gradient by picking a random ASCII character from the 4 (as specified by the `variance` variable) nearest the brightness of the originally predicted ASCII character in the previous bullet, giving a randomised, yet still clearly calculated feel.

### `print_fy()`

> Uses `f()` as $f(y)$, and thus prints $f(y)$ in the terminal.

Pretty much a carbon copy of `print_fx()`.
