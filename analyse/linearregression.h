/*
    Copyright 2012 Charit� Universit�tsmedizin Berlin, Institut f�r Radiologie
	Copyright 2010 Henning Meyer

	This file is part of KardioPerfusion.

    KardioPerfusion is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    KardioPerfusion is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with KardioPerfusion.  If not, see <http://www.gnu.org/licenses/>.

    Diese Datei ist Teil von KardioPerfusion.

    KardioPerfusion ist Freie Software: Sie k�nnen es unter den Bedingungen
    der GNU General Public License, wie von der Free Software Foundation,
    Version 3 der Lizenz oder (nach Ihrer Option) jeder sp�teren
    ver�ffentlichten Version, weiterverbreiten und/oder modifizieren.

    KardioPerfusion wird in der Hoffnung, dass es n�tzlich sein wird, aber
    OHNE JEDE GEW�HRLEISTUNG, bereitgestellt; sogar ohne die implizite
    Gew�hrleistung der MARKTF�HIGKEIT oder EIGNUNG F�R EINEN BESTIMMTEN ZWECK.
    Siehe die GNU General Public License f�r weitere Details.

    Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
    Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>.
*/

#ifndef LINEARREGRESSION_H
#define LINEARREGRESSION_H

#include <limits>

template<class ForwardIt, class float_t>
void LinearRegression(ForwardIt beginX, ForwardIt endX, ForwardIt beginY, float_t &b0, float_t &b1) {
  unsigned int n = 0;
  float_t sx = 0.0, sy = 0.0, sx2 = 0.0, sxy = 0.0;
  while(beginX < endX) {
    sx += *beginX;
    sx2 += *beginX * *beginX;
    sy += *beginY;
    sxy += *beginX * *beginY;
    n++;
    beginX++;
    beginY++;
  }
  float_t a = n;
  float_t b = sx;
  float_t c = sx;
  float_t d = sx2;
  float_t e = sy;
  float_t f = sxy;
  float_t detA = (a*d - b*c);
  if (detA != 0) {
    b0 = (e*d - b*f) / detA;
    b1 = (a*f - e*c) / detA;
  } else {
    b0 = std::numeric_limits< float_t >::max();
    b1 = std::numeric_limits< float_t >::max();
  }
}

#endif // LINEARREGRESSION_H