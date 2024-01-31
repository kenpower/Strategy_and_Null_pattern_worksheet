# Strategy and Null pattern worksheet

Run the code, make sure it compiles and executes before modifying.

## Instructions part 1 (strategy)

We want to be able to change the `Character`'s weapon at run time. At the moment, selecting a weapon does nothing. 
Using the strategy pattern create strategys for printing appropriate messages when the `Character` "attacks". 

### Two things you are allowed to do:

1.  Modify the commented code inside `charactersAttackwithStrategy()`
2.  Add new Concrete strategies classes

## Instruction part 2 (null)

in `Character::attack()` we have a possible null pointer (maybe dangerous), which we handle with an `if` guard. 
Can we leverage the strategy pattern to do the right thing by default, without having an `if` guard, without changing the overall behaviour?
You will need to modify the constructor and attack() function of Character.
Hint: Can the character have a "No weapon" weapon?

