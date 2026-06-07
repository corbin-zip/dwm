# Corbin's build of dwm

## FAQ

> What are the bindings?

Check out [config.h](config.h).

There is also a readme in `larbs.mom` for the full system, including all bindings, though this needs to be updated.
Press <kbd>super+F1</kbd> to view it in dwm (zathura is required for that binding).

## Patches and features

- [Clickable statusbar](https://dwm.suckless.org/patches/statuscmd/) with [dwmblocks](https://github.com/corbin-zip/dwmblocks).
- Reads [xresources](https://dwm.suckless.org/patches/xresources/) colors/variables (i.e. works with `pywal`, etc.).
- scratchpad: Accessible with <kbd>mod+shift+enter</kbd>. Scratchpads are shared across monitors - pressing the key on any monitor relocates the existing window rather than spawning a new instance.
- New layouts: bstack, fibonacci, deck, centered master and more. All bound to keys <kbd>super+(shift+)t/y/u/i</kbd>.
- True fullscreen (<kbd>super+f</kbd>) and prevents focus shifting.
- Windows can be made sticky (<kbd>super+s</kbd>).
- [hide vacant tags](https://dwm.suckless.org/patches/hide_vacant_tags/) hides tags with no windows.
- [stacker](https://dwm.suckless.org/patches/stacker/): Move windows up the stack manually (<kbd>super-K/J</kbd>).
- [shiftview](https://dwm.suckless.org/patches/nextprev/): Cycle through tags (<kbd>super+g/;</kbd>).
- [vanitygaps](https://dwm.suckless.org/patches/vanitygaps/): Gaps allowed across all layouts.
- [swallow patch](https://dwm.suckless.org/patches/swallow/): if a program run from a terminal would make it inoperable, it temporarily takes its place to save space.

## Installation

```bash
git clone https://github.com/corbin-zip/dwm.git
cd dwm
sudo make install
```

---

Forked from [Luke Smith's dwm](https://github.com/LukeSmithxyz/dwm).
