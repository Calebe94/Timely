#!/bin/bash

#This file is part of the Timely distribution (https://github.com/Calebe94/Timely).
#Copyright (C) 2021 Timely
#
#This program is free software: you can redistribute it and/or modify
#it under the terms of the GNU General Public License as published by
#the Free Software Foundation, either version 3 of the License, or
#(at your option) any later version.
#
#This program is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#GNU General Public License for more details.
#
#You should have received a copy of the GNU General Public License
#along with this program.  If not, see <http://www.gnu.org/licenses/>.

icon_ids=(
    "01"
    "02"
    "03"
    "04"
    "09"
    "10"
    "11"
    "11"
    "13"
    "50"
)

download_icons()
{
    for icon in "${icon_ids[@]}"; do
        echo "Downloading day $icon 50px..."
        wget "http://openweathermap.org/img/wn/${icon}d.png"
        echo "Downloading night $icon 50px..."
        wget "http://openweathermap.org/img/wn/${icon}n.png"
        
        echo "Downloading day $icon 100px..."
        wget "http://openweathermap.org/img/wn/${icon}d@2x.png"
        echo "Downloading night $icon 100px..."
        wget "http://openweathermap.org/img/wn/${icon}n@2x.png"

        echo "Downloading day $icon 200px..."
        wget "http://openweathermap.org/img/wn/${icon}d@4x.png"
        echo "Downloading night $icon 200px..."
        wget "http://openweathermap.org/img/wn/${icon}n@4x.png"
    done
}

echo "Initializing download proccess..."
download_icons
echo "done!"
