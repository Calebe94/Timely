# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Added

* Added comments to config file;
* Added `timely_app_t *current_app` pointer to store the opened app;
* Added methods to change context;
* Added style to watchface fonts;
* Added functions to manage the applications;

### Fixed

* Fixed typo in weather app;

### Changed

* Changed weather stock application by adding name and description labels;
* Renamed `timely_main` to `timely_watchface`;
* Renamed `timely_setup` to `timely_launcher`;

### Removed

* Removed unused event handler function;

## [0.1.0]

### Added

* Added `README.md` file with basic informations;
* Added `.gitignore` file to ignore `C` output files;
* Added `LICENCE` file with GPL3+ licence;
* Added `CMakeLists.txt` file;
* Added `timely.mk` make file;
* Added a simple tileview with the desired ui layout;
* Added lock screen prototype;
* Added weather and missed notifications to main tile;
* Added 48x48 pixels weather cloudy sun icon;
* Added weather data types based on OpenWeatherMap;
* Added script to download openweathermap weather icons on `scripts` folder;
* Added all OpenWeatherMap icons with 50x50, 100x100 and 200x200 pixels on `resources/icons` folder;
* Added `timely_app_t` struct with attributes and methods to initialize an app;
* Added a demo gif to `README.md`;
* Added a stock weather app;
* Added `CONTRIBUTING` file;
* Added `CODE_OF_CONDUCT` file;
* Added issue and pull request templates;

### Fixed

* Fixed labels misalignment;

### Changed

* Updated lock screen and added click event;

### Removed

[unreleased]: https://github.com/Calebe94/Timely/compare/0.1.0...HEAD
[0.1.0]: https://github.com/Calebe94/Timely/releases/tag/0.1.0
