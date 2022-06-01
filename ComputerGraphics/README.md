# Computer Graphics

Code for Computer Graphics Practical for [BSc.(H) Computer Science](<http://www.du.ac.in/du/uploads/RevisedSyllabi1/Annexure-83.%20(BSc(H)-Computer%20Science).pdf>)

<p align="center">
<img center src="./cube.gif" height="300">
</p>

### Set Up `<graphics.h>`

- Dowload and Install the **`32-bit`** GCC Compiler from [this link](https://jmeubank.github.io/tdm-gcc/download/)
- Download the required header files from [here](https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbURhWmRKSUk0MzhCbG9RLUt1Q1JNYzVtYlRSZ3xBQ3Jtc0tuam9FWEFjREo1Rm81UUwyYVZ6aVo0bXJtdWREX1pLUTB3V2hFeThEelBxeV9Sc2FrMXBqa2p1NWVaOURtUFdvWE92Z2M1ZC15MWdpV2RyZmozV0lmZjFNd2JSTTY2QzFmN1V4TThNSkwwR3BhZmpVTQ&q=https%3A%2F%2Fdrive.google.com%2Ffile%2Fd%2F16xZBvFXf7yFjxwTpuyevK1KPuLgUeZFh%2Fview%3Fusp%3Ddrivesdk)
- Extract the files and copy them as directed:
  - `graphics.h` and `winbgim.h` into the `include` folder inside `C:\TDM-GCC-32`
  - `libbgi.a` into the `lib` folder inside `C:\TDM-GCC-32`
  - **Note** - Depending on the Installation Location of TDM-GCC copy files accordingly

### Run Code

- To Compile any file with `graphics.h` use the following argumennts with `g++`

  ```
  g++ *FILENAME*.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
  ```

- After compiling `a.exe` file will be created that we can run.
- We can also set-up VS Code to Compile our Program using the `C++ Extension`. We will follow Part 1 of this guide to do so - [guide](https://www.youtube.com/watch?v=J0_vt-7Ok6U&t=659s). After this we can compile our program using `CTRL + SHIFT + B` and then run the exetuable.

#### Referernces

- [Set Up graphics.h in VS Code](https://www.youtube.com/watch?v=J0_vt-7Ok6U&t=659s)
- [Solution to graphics.h](https://github.com/ullaskunder3/Solution-to-graphics.h)

#### Notes

- I have linked the header files from [Set Up graphics.h in VS Code](https://www.youtube.com/watch?v=J0_vt-7Ok6U&t=659s) Video.The files avaialable at this [Official WinBGIm Site](https://winbgim.codecutter.org/) have bug a `line 302` (as far as I know - [stackoverflow](https://stackoverflow.com/a/46506655))
- This library is ancient and is used here only for academic purpose.
