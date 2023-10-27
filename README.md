# This
is a fork of <a href="https://interversehq.com/qview/">qView</a> which adds JPEGView-like zoom.

<img src="https://poodle.boats/media/qview_poodle.gif" >
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
- - it will <b> not </b> build from this github, but it seemed impolite to make a new repo instead of a fork
- you will probably need a few more packages than are suggested, just because of QT and your platform/distribution.

## TODO
- the entire project really should have just wrapped the current scroll wheel zoom within a setting, and rescaled the window if the setting is true.
 - - so, undo everything, and do that 

- troubleshoot disappearing image on extremely close zooms 
    
