# How to make a .exe file with a given icon

> We will take the example of compiling a `.cpp` using `g++` to generate a `.exe` file

## What do you need?

1. The `A.cpp` file which is to be compiled

2. The `my-icon.ico` file which is the desired icon for the .exe file
   
   - If the icon is in some other format (`.png`, `.jpg`, `jpeg`, and so on) then first convert it to `.ico` format
   
   - You will get some online converters for doing so. **For Example:** [Try This!](https://image.online-convert.com/convert-to-ico)

## Generating the configuration files

> - For some insights go to this documentation of `windres`:
>   [windres (GNU Binary Utilities)](https://sourceware.org/binutils/docs/binutils/windres.html)
> 
> - For our purpose, we will name this configuration file as `icon-config`
>   You can name it whatever you want

### (1) Creating the `icon-config.rc` file

- Create a file called `icon-config.rc` using either GUI or in Terminal/Console

- Paste the following code here:
  
  - ```rc
    id ICON "path/to/my-icon.ico"
    ```

- Close the file.

### (2) Compiling the `.rc` file to `.res`  using `windres`

- Type in the following in the Terminal
  
  - ```powershell
     windres icon-config.rc -O coff -o icon-config.res
    ```
  
  - **NOTE:**
    
    - `-O <file-format>` can also be written as:
      `--output-format=<file_format>`
    
    - `-o <file-name>` can also be written as:
      `--output=<output_filename>`
    
    - The File format can be either of the following: `rc`, `res`, `coff`

- After running this command, you should see a new file created, `icon-config.res`

## Using the Configuration Files to compile `A.cpp`

- While compiling the `A.cpp` file, you will use `A.cpp` and `icon-config.res` as the source files to generate the output file `A.exe`

- To do so, type in the following command:
  
  - ```powershell
    g++ A.cpp icon-config.res -o A.exe
    ```
  
  - **NOTE:**
    
    - `-o <output_filename>` can also be written as:
      `--output=<output_filename>`

## And you are done!

- The generated `A.exe` file will have the desired icon as chosen by you for the `my-icon.ico`
