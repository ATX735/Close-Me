# Introduction
This is a humiliating, boring and annoying game. The player's goal is to close this game. It's ridiculously easy to play, all you need to do is clicking and dragging.

It's a QT C++ beginner project. Anyone who interested in developing this project could contribute your code.

## Some Meaningless Screen Shot

![image-20220901103434177](https://raw.githubusercontent.com/ATX735/ATX735.github.io/main/IMG_Storage/202209011034246.png)

![image-20220901121448370](https://raw.githubusercontent.com/ATX735/ATX735.github.io/main/IMG_Storage/202209011214507.png)

![image-20220901103539814](https://raw.githubusercontent.com/ATX735/ATX735.github.io/main/IMG_Storage/202209011035864.png)

# For Developers

This section is the introduction of the project. It's written for boring developers who want to waste your precious time to contribute to this project .

### Project Structure

The structure of this project is pretty simple. The game started from `Start_Window` and then proceed into the `StoryLine`. The `StoryLine` folder contains several dialogs. Each dialog corresponds to a game dialog in this game. The number behind the dialog file name are incremental. The game ended when reaches the `End_Dlg`, which is in the root directory of this project.

**Summary:** 

- If you want to add a dialog(story) to the game, just add the dialog to the `StoryLine`
- If you are designing exit for a story, use the `End_Dlg` . Code Example:

```c++
QSharedPointer<End_Dlg> end = QSharedPointer<End_Dlg>(new End_Dlg(this));
end->exec();
```



### Documentation

We use Microsoft Visio graph to document the game process. You could find it in `Other` folder. It's a flow chart that illustrate the process of the game.

![GameProcess](https://raw.githubusercontent.com/ATX735/ATX735.github.io/main/IMG_Storage/202208311539798.png)

### Notice

- In C++ header file, use comment to indicate which function contains the way to proceed into `End_Dlg` and which function contains the way to the next `StoryLine` Dialog.
- Each dialog in `StoryLine` should public inherit the `DialogTemplate` class.  `DialogTemplate` class is store in `WindowTemplates` folder.

```c++
class Dialog_x : public DialogTemplate { ... };
```

- If you want to create a new window(a story window), constructor's parameter `parent` should set to `nullptr`. This is to prevent the icon in the windows mission bar disappear. For example create a new window like this:

```c++
QSharedPointer<Dialog_x> dlg = QSharedPointer<Dialog_x>(new Dialog_x(nullptr));
```

