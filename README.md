# This
is a fork of <a href="https://interversehq.com/qview/">qView</a> which adds JPEGView-like zoom.

![demonstration](example.gif)
<img src = "https://poodle.boats/media/qview_setting.png" style="width:60%;"/>

This change was added in a few hours solely from frustration. It mostly works to my expectations, as this is a make-or-break feature for me.
However, if this were to see other people's use, it should work more politely, and so there is more to do.

## Use
- scrolling over the window will scale up/down the window
- if the window would be larger than the display after a scroll, it zooms normally (bound within the window)
- When the setting is enabled, panning is broken unless the window is at its maximum size
- Requires "image scaling" to be enabled

## Install
- follow the <a href="https://github.com/jurplel/qView/wiki/Linux-Build-and-Install-Guide"> install guide </a> for dependencies and a working folder to build from
- - it will <b> not </b> build from this github alone, you must replace the src folder from the build guide with this one.
  - it seemed impolite and difficult to make a new repo instead of a fork, but that only made things more difficult for everyone else.
- you will probably need a few more packages than are suggested, just because of QT and your platform/distribution.
- The goal of this particular fork is not a merge, but a documentation that this happened for anyone who wanted to look up JPEGView alternatives for linux. If and when I understand how to implement this correctly, I will try and do so.

## TODO
- the entire project really should have just wrapped the current scroll wheel zoom within a setting, and rescaled the window if the setting is true.
 - - so, undo everything, and do that 

- troubleshoot disappearing image on extremely close zooms 
    
