# Kiosk Weather Markets Daily-News Dashboard

A **web-based dashboard** designed to run in **kiosk mode** on a **Raspberry Pi** (tested on RPi 3), at **Full HD resolution (1920×1080)**.

It will also work on any browser, any OS.

No backend, no accounts, no API keys.  
Built entirely with **HTML, CSS, and vanilla JavaScript**, using **public embeds**.

### Weather Page
![Weather](screenshot1.jpg)

### Markets Page
![Markets](screenshot2.jpg)

---

## Features

### Page 1 — Weather
- Interactive weather map (Windy)
- Fullscreen layout
- Designed for continuous display

### Page 2 — Markets
2×2 grid layout:
- List of **stock market indices** (ETF equivalents)
- Interactive chart (TradingView)
- List of **cryptocurrencies**
- Interactive chart (TradingView)

Charts update **on click**, without reloading the page.

### Page 3 — News
- **International news** (BBC)
- **National news** (Expresso)
- RSS feeds rendered via JavaScript
- Dark theme, optimized for soft reading

---

## Navigation
- Top tabs: **Weather / Markets / News**
- Mouse and touch friendly
- Ideal for dedicated screens or TVs

---

## Technologies
- HTML5
- CSS Grid
- Vanilla JavaScript
- Chromium (kiosk mode)
- TradingView embeds
- Windy embed
- Public RSS feeds (BBC / Expresso)

---

## Requirements
- Raspberry Pi 3 or newer  
- Raspberry Pi OS (Bullseye / Bookworm / Trixie)
- Chromium browser
- Screen resolution: **1920×1080**

---

## Kiosk Mode Example

```bash
chromium \
  --kiosk \
  --incognito \
  --disable-infobars \
  --noerrdialogs \
  --password-store=basic \
  --use-mock-keychain \
  --force-device-scale-factor=1.2 \
  file:///home/$HOME/dashboard.html

---

## Autostart

To add the .html Dashboard to the autostart
Create a folder autostart inside ./config
Copy the file dashboard_v2.html
It will open chromium in kiosk mode
To close - alt+F4  

---

## Customization

### Change Weather Location (Windy)

The Windy map location is defined by latitude and longitude in the iframe URL.

In `dashboard_v2.html`, locate the Windy iframe:

```html
<iframe
  src="https://embed.windy.com/embed2.html?lat=38.7223&lon=-9.1393&zoom=7&overlay=rain&product=ecmwf&metricTemp=%C2%B0C">
</iframe>

To change the location:

Replace lat with the desired latitude
Replace lon with the desired longitude

## Change Time & Date Location (Clock)

The clock uses the browser’s locale and system time by default.
In the JavaScript section, locate:

now.toLocaleTimeString('pt-PT', { ... })
now.toLocaleDateString('pt-PT', { ... })

Change language / date format

Replace 'pt-PT' with another locale, for example:

'en-GB' → English (UK)
'en-US' → English (US)
'de-DE' → German
'fr-FR' → French

--- 

## License
This project is licensed under the **Creative Commons Attribution-NonCommercial 4.0 International (CC BY-NC 4.0)**.

You are free to:
- Share — copy and redistribute the material
- Adapt — remix, transform, and build upon the material

Under the following terms:
- Attribution — you must give appropriate credit
- NonCommercial — you may not use the material for commercial purposes

License details:  
https://creativecommons.org/licenses/by-nc/4.0/
