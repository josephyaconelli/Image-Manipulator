# Image-Manipulator
C++ Image Manipulator

A simple command line image manipulator for PNM images.

## Filters:
+ Shrinker
+ Left-Right Concatenation
+ Top-Bottom Concatenation
+ Two Image Blender

## Add Filter:
1. Initialize filter in the `main()` function in main.C

  ```
  FilterName filter;
  ```
2. Set input(s) to the previous filter's output:

  ```
  filter.SetInput(prevFilter.GetOutput());
  ```
  
  or for filters requiring two inputs:
  
  ```
  filter.SetInput(prevFilter1.GetOutput());
  filter.SetInput2(preFilter2.GetOutput());
  ```
3. Set the next filter's input as `filter `'s output:
  * If `filter` isn't the last one, set the next input as it's output:
    ```
    nextFilter.SetInput(filter.GetOutput);
    ```
  * If `filter` is the last one, write:
    ```
    filter.GetOutput()->Update();
    ``` 

## Create Filter:
1. Declare new filter in `filters.h` and extend `public Filter`:

  ```
  class MyFilter : public Filter
  {
    public:
      virtual void Execute();
      /* any other methods you'll need... */
  };
  ```
2. Implement `MyFilter::Execute()` in `filters.C`:

  ```
  void
  MyFilter::Execute()
  {
    /* filter implementation */
  }
  
  /* implement any other methods you'll need...*/
  ```
  ####NOTE: you can use indP(i, j, width) to access the pixel at i,j
  
3. Add `MyFilter` to `main.C` using the steps under __Add Filter__
