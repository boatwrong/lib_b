# <string.h> sucks! Make it better.

## Break down task

### No <string.h> dependency

* If the lib needs one that's fine, but it better be self contained.

### No manual mallocing!

* I want just a constructor/destructor setup ( READ: I am lazy )

### Very concise

* One constructor, one destructor, 2-3 modification functions tops.

### What makes up a string

* array of characters
    * is it going to change length ? 
    * is contents going to change ?

## Tasks

* Make a better array... aka the List<> of C# but without the fluff.
    * List struct
    * List memory management
    * List functions

* string is just array of chars...
    * String struct
    * String specific functions

??? wchars too ???
