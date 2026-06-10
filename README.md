# Corbin's build of dwm

## FAQ

> What are the bindings?

There is a readme in `larbs.mom` for the full system, though this needs to be updated. Press <kbd>super+F1</kbd> to view it in dwm (requires zathura).

## Patches and features

- [Clickable statusbar](https://dwm.suckless.org/patches/statuscmd/) with [dwmblocks](https://github.com/corbin-zip/dwmblocks).
- Reads [xresources](https://dwm.suckless.org/patches/xresources/) colors/variables (i.e. works with `pywal`, etc.). <kbd>super+F5</kbd> reloads them live, numeric settings included, no restart needed.
- Six named scratchpads (terminal, calculator, keepassxc, anki, etc.), main one on <kbd>mod+shift+enter</kbd>. Scratchpads are shared across monitors: pressing the key on any monitor relocates the existing window rather than spawning a new instance.
- New layouts: bstack, fibonacci, deck, centered master and more. All bound to keys <kbd>super+(shift+)t/y/u/i</kbd>.
- True fullscreen (<kbd>super+f</kbd>) and prevents focus shifting.
- Windows can be made sticky (<kbd>super+s</kbd>).
- [hide vacant tags](https://dwm.suckless.org/patches/hide_vacant_tags/) hides tags with no windows.
- [stacker](https://dwm.suckless.org/patches/stacker/): Move windows up the stack manually (<kbd>super-K/J</kbd>).
- [shiftview](https://dwm.suckless.org/patches/nextprev/): Cycle through tags (<kbd>super+g/;</kbd>).
- [vanitygaps](https://dwm.suckless.org/patches/vanitygaps/): Gaps allowed across all layouts.
- [swallow patch](https://dwm.suckless.org/patches/swallow/): if a program run from a terminal would make it inoperable, it temporarily takes its place to save space.

## Fixes and performance

Stacking this many patches on dwm can lead to issues so this build has had a "proper" bug hunt over the whole tree using Claude Code with Fable 5. Highlights from the commit history:

- tag label widths are cached instead of remeasured on every drawbar, and XSync is called once per arrange instead of after every single resize, which makes layout changes noticeably snappier
- fixed an infinite loop in shiftview when only scratchpad tags were in view, and out-of-range shift counts in shifttag
- scratchpad tags are excluded from view-all/tag-all, and a scratchpad that is the only tag in view can now be hidden
- swallow parses `/proc` stat correctly for process names containing spaces
- SIGHUP/SIGTERM take effect immediately via a self-pipe instead of waiting for the next X event
- fixed deck layout heights when nmaster is 0, a stale all-tags sentinel in the hide-vacant-tags code, and spawn leaving zombie children behind when execvp fails

## Installation

```sh
git clone https://github.com/corbin-zip/dwm.git
cd dwm
sudo make install
```

Originally forked from [Luke Smith's dwm](https://github.com/LukeSmithxyz/dwm), with a round of bugfixes and performance work on top (as described above).
