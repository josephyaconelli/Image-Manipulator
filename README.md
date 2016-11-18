# Image-Manipulator
C++ Image Manipulator

A simple command line image manipulator for PNM images.

## Filters:
+ Shrinker
+ Left-Right Concatenation
+ Top-Bottom Concatenation
+ Two Image Blender

## To Change Which Filters Are Applied:
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
