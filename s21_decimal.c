#include "s21_decimal.h"
#include <stdio.h>

// Суть этой функции в том что она перекидывает лишние
// биты в более старший int. Используется повсеместно
int getoverflow(work_decimal *dec) {
  int overflow = 0;

  // Проверяем все int в нашем расширенном decimal на то что в них
  // записано больше чем 32 бита (предел стандартного 32битного
  // int), если больше то перекидываем всё лишнее на int вверх
  for (int i = 0; i < 7; i++) {
    dec->bits[i] += overflow;
    overflow = (dec->bits[i] >> 32);
    dec->bits[i] &= MAX4BITE;
  }
  int result = 0;

  // Если нам не хватило даже наших дополнительных int то это
  // переполнение и мы возвращаем единицу
  if (overflow) {
    result = 1;
  }
  return result;
}

// смещаем нашу воображаемую точку влево
// умножая все int на 10 и увеличиваем scale
int pointleft(work_decimal *dec) {
  work_decimal temp_dec = *dec;
  for (int i = 0; i < 7; i++) {
    temp_dec.bits[i] *= 10;
  }
  temp_dec.scale++;
  int overflowed = 0;

  // так как мы в процессе увеличиваем весь decimal,
  // нужно проверить это дело на переполнение
  if (getoverflow(&temp_dec)) {
    overflowed = 1;
  } else {
    *dec = temp_dec;
  }
  return overflowed;
}

// смещаем нашу воображаемую точку вправо
// деля все int на 10, уменьшая scale
int pointright(work_decimal *dec) {
  long int remainder = 0;
  for (int i = 6; i >= 0; i--) {
    dec->bits[i] +=
        remainder << 32;  // тут мы уже записывает остаток в конец меньшего int
    remainder = dec->bits[i] % 10;  // остаток от будущего деления
    dec->bits[i] /= 10;
  }
  dec->scale--;
  return remainder;
}

// функция подготовки work_decimal к нашему
// нормальному s21_decimal
int normalize(work_decimal *dec, const int summ, const int sign) {
  int trash = 0;
  int error = 0;
  int last = 0;
  work_decimal temp_dec = *dec;

  for (int i = 6; i > 2; i--) {
    // перетягиваем все int из work_decimal чтобы они уместились в
    // обычный s21_decimal, если нам позволяет scale, то есть
    // должны остаться лишь три низших int, иначе переполнение
    while (temp_dec.bits[i] != 0 && temp_dec.scale > 0) {
      last = pointright(&temp_dec);
      trash += last;
    }
    if (((last > 5 || last == 5) && trash > 5) ||
        (last == 5 && trash == 5 &&
         (temp_dec.bits[0] % 10) % 2 == 1)) {  // банковское округление
      if (!sign) {
        temp_dec.bits[0]++;
        getoverflow(&temp_dec);
      }
    }
  }

  // если нормализируем из какой-нибудь функции сложения, то если все биты
  // заполенены и есть еще мусор, значит случилось переполнение
  if (summ && trash && temp_dec.bits[0] == 0xffffffff &&
      temp_dec.bits[1] == 0xffffffff && temp_dec.bits[2] == 0xffffffff) {
    error = 1;
  }

  for (int i = 3; i < 7; i++) {
    // проверяем свободны ли int старше 3-го, если
    // нет то это переполнение
    if (temp_dec.bits[i] != 0 && temp_dec.scale == 0) {
      error = 1;
      i = 7;
    }
  }

  // никакого переполнения нету, всё хорошо, можно переписывать
  // work_decimal
  if (!error) {
    *dec = temp_dec;
  }

  return error;
}

// создаем расширенный work_decimal с бОльшим количеством int (и
// сами int больше) на основе обычного s21_decimal
work_decimal decimal_to_work(s21_decimal dec) {
  work_decimal result;
  result.bits[0] = dec.bits[0] & MAX4BITE;
  result.bits[1] = dec.bits[1] & MAX4BITE;
  result.bits[2] = dec.bits[2] & MAX4BITE;
  result.bits[3] = 0;
  result.bits[4] = 0;
  result.bits[5] = 0;
  result.bits[6] = 0;
  result.scale = (dec.bits[3] & SC) >> 16;
  return result;
}

// обратная история
s21_decimal work_to_decimal(work_decimal dec) {
  s21_decimal result;
  result.bits[0] = dec.bits[0] & MAX4BITE;
  result.bits[1] = dec.bits[1] & MAX4BITE;
  result.bits[2] = dec.bits[2] & MAX4BITE;
  result.bits[3] = 0;
  result.bits[3] |= (dec.scale << 16);
  return result;
}

// преобразуем оба децимала на один scale, для
// удобства вычислений. Так как нам удобнее
// домнажать на 10, мы это и делаем здесь
void point_to_normal(work_decimal *dec1_work, work_decimal *dec2_work) {
  if (dec1_work->scale < dec2_work->scale) {
    // домножаем первый, если он меньше
    while (dec1_work->scale != dec2_work->scale && !pointleft(dec1_work))
      ;
  } else if (dec2_work->scale < dec1_work->scale) {
    // домножаем второй, если он меньше
    while (dec1_work->scale != dec2_work->scale && !pointleft(dec2_work))
      ;
  }
}

// проверка всех int на тождественность в
// расширенном децимале
int work_is_equal(work_decimal dec1_work, work_decimal dec2_work) {
  int res = 1;
  for (int i = 6; i >= 0; i--) {
    if (dec1_work.bits[i] != dec2_work.bits[i]) {
      res = 0;
    }
  }
  return res;
}

int s21_is_equal(s21_decimal dec1, s21_decimal dec2) {
  int res = 1;

  // если все биты равны нулю, но знак разный то
  // децималы всё равно равны, по условию
  if ((dec1.bits[3] & MINUS) != (dec2.bits[3] & MINUS) &&
      ((dec1.bits[0] == dec2.bits[0]) && (dec1.bits[1] == dec2.bits[1]) &&
       (dec1.bits[2] == dec2.bits[2]) && (dec1.bits[0] == 0) &&
       (dec1.bits[1] == 0) && (dec1.bits[2] == 0))) {
    res = 1;

    // иначе если знак разный то они не равны
  } else if ((dec1.bits[3] & MINUS) != (dec2.bits[3] & MINUS)) {
    res = 0;

    // иначе нужно привести их к одному scale и сравнить
  } else {
    work_decimal dec1_work, dec2_work;

    // переводит наши децималы в расширенные, чтобы
    // можно было удобно домножить на 10 и сравнить
    dec1_work = decimal_to_work(dec1);
    dec2_work = decimal_to_work(dec2);

    // домножаем один из расширенных децималов, если нужно
    point_to_normal(&dec1_work, &dec2_work);
    for (int i = 2; i >= 0; i--) {
      // если различий в трех низших int нету, значит
      // они равны
      if (dec1_work.bits[i] != dec2_work.bits[i]) {
        res = 0;
      }
    }
  }
  return res;
}

int work_is_less(work_decimal dec1_work, work_decimal dec2_work) {
  int res = 0;
  for (int i = 6; i >= 0; i--) {
    // если в верхнем int первого децимал меньше значение
    // то значит и весь первый децимал меньше второго
    if (dec1_work.bits[i] < dec2_work.bits[i]) {
      res = 1;
      i = -1;

      // если в верхнем int первого децимал
      // больше значение то значит и весь первый
      // децимал больше второго
    } else if (dec1_work.bits[i] > dec2_work.bits[i]) {
      res = 0;
      i = -1;
    }
  }
  return res;
}

int s21_is_less(s21_decimal dec1, s21_decimal dec2) {
  int res = 1;

  // если децималы равны или второй отрицательный а первый нет
  if ((dec1.bits[3] & MINUS) < (dec2.bits[3] & MINUS) ||
      s21_is_equal(dec1, dec2)) {
    res = 0;

    // если первый децимал отрицательный, а
    // второй нет, то первый меньше
  } else if ((dec1.bits[3] & MINUS) > (dec2.bits[3] & MINUS)) {
    res = 1;
  } else {
    work_decimal dec1_work, dec2_work;
    dec1_work = decimal_to_work(dec1);
    dec2_work = decimal_to_work(dec2);
    point_to_normal(&dec1_work, &dec2_work);  // приводим к одному scale
    for (int i = 2; i >= 0; i--) {
      // если в верхнем int первый децимал меньше то
      // значит и весь первый децимал меньше второго
      if (dec1_work.bits[i] < dec2_work.bits[i]) {
        res = 1;
        i = -1;

        // если в верхнем int первый децимал больше то
        // значит и весь первый децимал больше второго
      } else if (dec1_work.bits[i] > dec2_work.bits[i]) {
        res = 0;
        i = -1;
      }
    }

    // если оба децимала были отрицательными но
    // инвертируем результат
    if (dec1.bits[3] & MINUS) {
      res ? (res = 0) : (res = 1);
    }
  }
  return res;
}

// просто используем функции написанные выше и
// комбинируем их если надо
int s21_is_less_or_equal(s21_decimal dec1, s21_decimal dec2) {
  int res = 0;
  if (s21_is_equal(dec1, dec2) || s21_is_less(dec1, dec2)) {
    res = 1;
  }
  return res;
}

int s21_is_greater(s21_decimal dec1, s21_decimal dec2) {
  int res = 1;
  if (s21_is_less_or_equal(dec1, dec2)) {
    res = 0;
  }
  return res;
}

int s21_is_greater_or_equal(s21_decimal dec1, s21_decimal dec2) {
  int res = 1;
  if (s21_is_less(dec1, dec2)) {
    res = 0;
  }
  return res;
}

int s21_is_not_equal(s21_decimal dec1, s21_decimal dec2) {
  int res = 1;
  if (s21_is_equal(dec1, dec2)) {
    res = 0;
  }
  return res;
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0;

  // сразу переводим наши децималы в расширенные
  work_decimal dec1_work = decimal_to_work(value_1),
               dec2_work = decimal_to_work(value_2);
  work_decimal temp_result = {{0, 0, 0, 0, 0, 0, 0}, 0};
  point_to_normal(&dec1_work, &dec2_work);  // выравниваем scale

  // числа одинаковые по знакам
  if ((value_1.bits[3] & MINUS) == (value_2.bits[3] & MINUS)) {
    // просто складываем все int и переводим
    // лишние биты в int повыше если нужно
    for (int i = 0; i < 6; i++) {
      temp_result.bits[i] += dec1_work.bits[i] + dec2_work.bits[i];
      getoverflow(&temp_result);
    }

    // в результатирующий расширенный децимал складываем scale
    temp_result.scale = dec1_work.scale;

    // нормализуем для последующей конвертации в обычный
    // децимал. Если есть переполнение то с помощью знака
    // понимаем в какую сторону переполнение
    if (normalize(&temp_result, 1, value_1.bits[3] & MINUS)) {
      if (value_1.bits[3] & MINUS) {
        res = 2;
      } else {
        res = 1;
      }
    } else {
      // складываем всё в наш результирующий обычный децимал
      *result = work_to_decimal(temp_result);
      // знак
      if (value_1.bits[3] & MINUS) {
        result->bits[3] |= MINUS;
      }
      result->bits[3] |= (temp_result.scale << 16) & SC;  // scale
    }
  } else {  // числа разные по знакам

    // заранее запоминаем какой знак у какого децимала
    int first_minus = (value_1.bits[3] & MINUS);
    int second_minus = (value_2.bits[3] & MINUS);

    // делаем оба децимала положительными
    value_1.bits[3] &= ~MINUS;
    value_2.bits[3] &= ~MINUS;
    for (int i = 0; i < 6; i++) {
      // вычитаем из большего децимала меньший
      if (s21_is_less(value_1, value_2)) {
        // вычитаем с помощью инвертирования int меньшего децимала
        temp_result.bits[i] += dec2_work.bits[i] + (~dec1_work.bits[i] + 1);
      } else {
        temp_result.bits[i] += dec1_work.bits[i] + (~dec2_work.bits[i] + 1);
      }
      getoverflow(&temp_result);
    }

    // передаем scale результатирующему расширенному децималу
    temp_result.scale = dec1_work.scale;
    int res_sign = 0x00000000;

    // решаем какой будет в итоге знак у результата
    if ((s21_is_less(value_1, value_2) && second_minus) ||
        (s21_is_greater(value_1, value_2) && first_minus)) {
      res_sign |= MINUS;
    }
    normalize(&temp_result, 0, res_sign);
    *result = work_to_decimal(temp_result);  // передаем все данные результату
    result->bits[3] |= res_sign;
    result->bits[3] |= (temp_result.scale << 16) & SC;
  }
  return res;
}

// функция для вычитания расширенных децималов
int work_sub(work_decimal value_1, work_decimal value_2, work_decimal *result) {
  int res = 0;
  work_decimal temp_result = {{0, 0, 0, 0, 0, 0, 0}, 0};

  // вычисляем каждый int с помощью инвертирования
  // меньшего расширенного децимала
  for (int i = 0; i < 7; i++) {
    temp_result.bits[i] += value_1.bits[i] + (~value_2.bits[i] + 1);
    getoverflow(&temp_result);
  }
  *result = temp_result;
  return res;
}

// просто инвертируем знак для второго децимала и
// складываем с помощью нашего s21_add
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  value_2.bits[3] = (value_2.bits[3] & MINUS) ? value_2.bits[3] & ~MINUS
                                              : value_2.bits[3] | MINUS;
  return s21_add(value_1, value_2, result);
}

work_decimal binary_mul(s21_decimal value_1, s21_decimal value_2) {
  work_decimal result = {{0, 0, 0, 0, 0, 0}, 0};
  work_decimal temp = decimal_to_work(value_1);

  int max_bit = -1;

  for (int i = 128 - 1; i >= 0; i--) {
    if ((!!(value_2.bits[i / 32] & (1U << i % 32)))) {
      max_bit = i;
      break;
    }
  }

  for (int i = 0; i <= max_bit; i++) {
    if (!!(value_2.bits[i / 32] & (1U << i % 32)) != 0) {
      work_decimal tmp2 = temp;

      while (!(tmp2.bits[0] == 0 && tmp2.bits[1] == 0 && tmp2.bits[2] == 0 &&
               tmp2.bits[3] == 0 && tmp2.bits[4] == 0 && tmp2.bits[5] == 0 &&
               tmp2.bits[6] == 0)) {
        work_decimal overflow_bits;

        work_decimal result2 = {{0, 0, 0, 0, 0, 0}, 0};
        result2.bits[0] = result.bits[0] & tmp2.bits[0];
        result2.bits[1] = result.bits[1] & tmp2.bits[1];
        result2.bits[2] = result.bits[2] & tmp2.bits[2];
        result2.bits[3] = result.bits[3] & tmp2.bits[3];

        result2.bits[4] = result.bits[4] & tmp2.bits[4];
        result2.bits[5] = result.bits[5] & tmp2.bits[5];
        result2.bits[6] = result.bits[6] & tmp2.bits[6];

        overflow_bits = result2;

        bit_left(&overflow_bits, 1);

        result.bits[0] = result.bits[0] ^ tmp2.bits[0];
        result.bits[1] = result.bits[1] ^ tmp2.bits[1];
        result.bits[2] = result.bits[2] ^ tmp2.bits[2];
        result.bits[3] = result.bits[3] ^ tmp2.bits[3];

        result.bits[4] = result.bits[4] ^ tmp2.bits[4];
        result.bits[5] = result.bits[5] ^ tmp2.bits[5];
        result.bits[6] = result.bits[6] ^ tmp2.bits[6];

        tmp2 = overflow_bits;
      }
    }
    bit_left(&temp, 1);
  }
  return result;
}

int multiplication(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result) {
  int error = 0;
  error = value_1.bits[0] + value_2.bits[0];
  *result = value_1;
 /* int scale1 = (value_1.bits[3] & SC) >> 16;
  int scale2 = (value_2.bits[3] & SC) >> 16;

  value_1.bits[3] = 0;
  value_2.bits[3] = 0;

  work_decimal dec_work = binary_mul(value_1, value_2);

  int shift = 0;

  if (!(dec_work.bits[0] == 0 && dec_work.bits[1] == 0 &&
        dec_work.bits[2] == 0 && dec_work.bits[3] == 0 &&
        dec_work.bits[4] == 0 && dec_work.bits[5] == 0 &&
        dec_work.bits[6] == 0)) {
    work_decimal maxi = {{0xffffffff, 0xffffffff, 0xffffffff, 0, 0, 0, 0}, 0};
    
        s21_int256 quotient = s21_int256_binary_division(value, max, NULL);

            // Перебираем все степени 10, чтобы найти ближайшую большую степень,
       чем quotient
            // Делаем так, потому что это гораздо быстрее, чем делить на 10 в
       цикле while (1) { int compare =
       s21_int128_binary_compare(quotient.decimals[0],
       s21_int128_get_ten_pow(shift)); if (compare == -1 || compare == 0) {
                    break;
                }
                ++shift;
            }

            // Проверяем, что value впишется в 96 бит, если поделить на 10 в
       найденной степени work_decimal tmp = s21_int256_binary_division( value,
       s21_create_int256_from_decimal(s21_int128_get_ten_pow(shift)), NULL);
            // Если не помещается, то берем следующую степень
            if (!s21_int128_binary_equal_zero(tmp.decimals[1]) ||
       tmp.decimals[0].bits[3] != 0) {
                ++shift;
            }
    
  }
*/
  return error;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = 0;

  if (!result) {
    error = 4;
  } else {
    s21_decimal temp_dec = {{0, 0, 0, 0}};

    error = multiplication(value_1, value_2, &temp_dec);

    if ((value_1.bits[3] & MINUS) != (value_2.bits[3] & MINUS)) {
      s21_negate(temp_dec, &temp_dec);
    }

    if (error == 1) {
      if (temp_dec.bits[3] & MINUS) {
        error = 2;
      }
    }

    if (error == 0 && s21_is_not_equal(value_1, (s21_decimal){{0, 0, 0, 0}}) &&
        s21_is_not_equal(value_2, (s21_decimal){{0, 0, 0, 0}}) &&
        s21_is_equal(temp_dec, (s21_decimal){{0, 0, 0, 0}})) {
      error = 2;
    }

    *result = temp_dec;
  }

  return error;

  /*int res = 0;
  work_decimal dec1_work = decimal_to_work(value_1),
               dec2_work = decimal_to_work(value_2);
  work_decimal temp_dec = {{0, 0, 0, 0, 0, 0, 0}, 0};

  // умножаем все int между собой по вот
  // такой интересной и простой формуле
  temp_dec.bits[0] = dec1_work.bits[0] * dec2_work.bits[0];
  temp_dec.bits[1] = dec1_work.bits[1] * dec2_work.bits[0] +
                     dec1_work.bits[0] * dec2_work.bits[1];
  temp_dec.bits[2] = dec1_work.bits[2] * dec2_work.bits[0] +
                     dec1_work.bits[1] * dec2_work.bits[1] +
                     dec1_work.bits[0] * dec2_work.bits[2];
  temp_dec.bits[3] = dec1_work.bits[1] * dec2_work.bits[2] +
                     dec1_work.bits[2] * dec2_work.bits[1];
  temp_dec.bits[4] = dec1_work.bits[2] * dec2_work.bits[2];

  getoverflow(&temp_dec);
  int res_sign = 0;

  // вычисляем знак
  if ((value_1.bits[3] & MINUS) != (value_2.bits[3] & MINUS)) {
    res_sign = 1;
  } else {
    res_sign = 0;
  }

  // проверяем на переполнение
  if (normalize(&temp_dec, 1, res_sign)) {
    if (res_sign) {
      res = 2;
    } else {
      res = 1;
    }

    // если всё нормально
  } else {
    *result = work_to_decimal(temp_dec);
    if (res_sign) {
      result->bits[3] |= MINUS;
    }
    result->bits[3] |=
        (value_1.bits[3] & SC) + (value_2.bits[3] & SC);  // суммируем скейлы
  }
  return res;*/
}

// сдвиг битов влево на shift единиц
void bit_left(work_decimal *dec1_work, int shift) {
  int max = shift / 32;

  // если у нас слишком большой shift то
  // сдвигаем сразу весь int в следующий int
  for (int i = 0; i < max; i++) {
    for (int j = 0; j < 7; j++) {
      dec1_work->bits[j] <<= 32;
    }
    getoverflow(dec1_work);
  }

  // сдвигаем по единичке
  for (int i = 0; i < shift % 32; i++) {
    for (int j = 0; j < 7; j++) {
      dec1_work->bits[j] <<= 1;
    }
  }
  getoverflow(dec1_work);
}

// тут мы ищем самое большое число которое можно
// вычесть из dec1_work
void div_upper_loop(work_decimal *temp_dec, const work_decimal *dec2_work,

                    work_decimal *dec1_work, int sign, int *res,
                    work_decimal *dec3_work) {
  for (int i = 96; i >= 0; i--) {
    *temp_dec = *dec2_work;
    bit_left(temp_dec, i);  // сдвигаем на i битов влево

    // если получается что temp_dec (а он же просто dec2_work
    // сдвинутый на i битов влево) меньше чем dec1_work и i даже
    // на последнем 96 бите, то это переполнение, остается
    // узнать знак переполнения
    if (work_is_less(*temp_dec, *dec1_work) && i == 96) {
      if (!sign) {
        *res = 1;
      } else {
        *res = 2;
      }
      i = -1;
    }
    // если текущий temp_dec меньше или равен dec1_work то смело вычитаем и
    // записываем бит в результат
    if ((work_is_less(*temp_dec, *dec1_work) ||
         work_is_equal(*dec1_work, *temp_dec)) &&
        i >= 0) {
      dec3_work->bits[i / 32] |=
          1 << (i % 32);  // i биту dec3_work присваиваем единицу

      // соответсвенно если мы нашли такое число то вычитаем
      work_sub(*dec1_work, *temp_dec, dec1_work);
    }
  }
}

void div_down_loop(work_decimal *temp_dec, const work_decimal *dec2_work,

                   work_decimal *dec1_work, work_decimal *dec3_work, int *scale,
                   int *temp_div, int *is_it_first_loop) {
  // умножаем каждый раз результат и делимое на 10 и прибавляем
  // единичку к скейлу чтобы продолжить вычислять результат
  pointleft(dec1_work);
  pointleft(dec3_work);
  *scale = (*scale) + 1;
  *temp_div = 0;
  for (int i = 3; i >= 0; i--) {
    *temp_dec = *dec2_work;

    // сдвигаем temp_dec на i битов влево
    bit_left(temp_dec, i);

    // если мы нашли самый большой temp_dec который
    // меньше dec1_work то можно приступать к вычитанию
    if (work_is_less(*temp_dec, *dec1_work) ||
        work_is_equal(*dec1_work, *temp_dec)) {
      // если это самый первый проход цикла, то ставим
      // единичку на i место самого низшего int
      // результата
      if (*is_it_first_loop) {
        dec3_work->bits[0] |= 1 << i;

        // если это уже не самый первый проход цикла, то записываем
        // результат уже в другу переменную
      } else {
        *temp_div = *temp_div | 1 << i;
      }

      // обозначаем что самый первый проход цикла был
      // завершен и dec3_work->bits[0] был присвоен свой
      // бит для необходимого результата
      *is_it_first_loop = 0;

      // вычитаем из делимого (dec1_work) преобразованный
      // побитовым сдвигом делитель
      work_sub(*dec1_work, *temp_dec, dec1_work);
    }
  }

  // если уже был соверешен хотя бы одна операция в
  // цикле повыше то можно плюсовать к нему наш
  // temp_div результат тем самым всё ближе и ближе
  // подходя к конечному результату
  if (!(*is_it_first_loop)) {
    dec3_work->bits[0] = dec3_work->bits[0] + *temp_div;
  }
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0;

  // если второй децимал равен нулю то это ошибка
  // номер 3, нельзя делить на ноль
  if (s21_is_equal(value_2, (s21_decimal){{0, 0, 0, 0}})) {
    res = 3;
  } else {
    int sign = 0;

    // если знаки разные то в итоге знак минус
    if ((value_1.bits[3] & MINUS) != (value_2.bits[3] & MINUS)) {
      sign = 1;
    }
    work_decimal dec1_work = decimal_to_work(value_1),
                 dec2_work = decimal_to_work(value_2),
                 dec3_work = {{0, 0, 0, 0, 0, 0, 0}, 0};
    point_to_normal(&dec1_work, &dec2_work);  // приводим к одному scale
    int scale = dec1_work.scale - dec2_work.scale;
    work_decimal temp_dec = dec2_work;

    // вычисляем наибольший делитель для dec1_work,
    // посредством цикла который смещает биты dec2_work от 96
    // до 0 и каждый раз проверяет, меньше ли теперь dec2_work
    // или не нужно так сильно сдвигать биты
    div_upper_loop(&temp_dec, &dec2_work, &dec1_work, sign, &res, &dec3_work);
    int temp_div = 0;
    int is_it_first_loop = 1;

    // пока скейл меньше 30 (специально 30 а не 28, чтобы
    // можно было сделать округление в крайнем случае),
    // переполнения нету и dec1_work не равен нулу
    while (
        scale < 30 && !res &&
        !work_is_equal(dec1_work, (work_decimal){{0, 0, 0, 0, 0, 0, 0}, 0})) {
      // постепенно вычитаем из делимого наш
      // преобразованный побитовым сдвигом делитель и
      // записываем нужный бит в результат, каждый раз
      // прибавляя к скейлу единицу
      div_down_loop(&temp_dec, &dec2_work, &dec1_work, &dec3_work, &scale,
                    &temp_div, &is_it_first_loop);
    }
    if (normalize(&dec3_work, 1, sign)) {  // Нормализуем
      (!sign) ? (res = 1) : (res = 2);
    } else {
      dec3_work.scale = 0;
      *result = work_to_decimal(dec3_work);
      if (sign) {  // присваиваем знак
        result->bits[3] |= MINUS;
      } else {
        result->bits[3] &= ~MINUS;
      }
      result->bits[3] |= (scale << 16) & SC;  // scale
    }
  }
  return res;
}

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  s21_decimal temp_dec = {{0, 0, 0, 0}};
  temp_dec.bits[3] = (src < 0) ? MINUS : 0;  // вычисляем знак src

  // просто передаем src нашему int, но уже без
  // последнего бита, так как мы его отдельно записали
  // в наш 4 int, если же src отрицательное число, то
  // нам нужно его инвертировать (что поделать, так
  // устроен signed int)
  temp_dec.bits[0] = (src < 0) ? (~src & ~MINUS) + 1 : src & ~MINUS;
  *dst = temp_dec;
  return 0;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int res = 0;
  work_decimal dec_work = decimal_to_work(src);
  int scale =
      (((src.bits[3] & SC) >> 16) > 28) ? 28 : ((src.bits[3] & SC) >> 16);

  // отбрасываем все цифры после точки, всю
  // вещественную часть децимал
  for (int i = 0; i < scale; i++) {
    pointright(&dec_work);
  }

  // проверяем не переполнен ли у нас децимал. должен быть занят
  // только самый низший int, чтобы небыло переполнения
  for (int i = 6; i > 0; i--) {
    if (dec_work.bits[i] != 0) {
      res = 1;
      i = 0;
    }
  }
  if (!res) {
    // передаем из нашено int в dst int
    *dst = dec_work.bits[0];

    // умножаем dst на -1 если децимал отрицательный
    *dst *= (src.bits[3] & MINUS) ? -1 : 1;
  }
  return res;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  double temp_result = 0;  // временный результат
  int offset = 0;

  // проверяем каждый наш бит в децимале. Прибавляем к нашему
  // временному double результату бит переведенный из двоичной
  // системы в десятичную
  for (int i = 0; i < 96; i++) {
    if ((src.bits[i / 32] & (1l << i % 32))) {  // добавил буковку l к 1

      double temp_pow = 1;
      for (int j = 0; j < i; j++) {
        temp_pow *= 2;
      }
      temp_result += temp_pow;
    }
  }

  // вычисляем смещение точки, если оно больше нуля то делим наш
  // результат на 10 пока точка не будет в нужном месте
  if ((offset = (src.bits[3] & ~MINUS) >> 16) > 0) {
    for (int i = offset; i > 0; i--) {
      temp_result /= 10.;
    }
  }
  *dst = (float)temp_result;  // переводим double результат в float
  *dst *= (src.bits[3] & MINUS) ? -1 : 1;  // умножаем на -1 если таков знак
  return 0;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  s21_decimal temp_dec = {{0, 0, 0, 0}};
  *dst = temp_dec;

  if (src != src || (src == 1. / 0.) || (src == 1. / -0.))
    return 1;  // из -+бесконечности или НЕ ЧИСЛА нельзя перевести, ошибка

  // если число отрицательное, сразу пишем это в результат и
  // делаем из src положительное число
  if (src < 0) {
    temp_dec.bits[3] |= MINUS;
    src = -src;
  }

  *dst = temp_dec;

  // эта конструкция нужна чтобы читать побитово float с
  // помощью unsigned int
  union {
    float f;
    uint32_t u;
  } fu = {.f = src};

  int exp = ((fu.u & ~MINUS) >> 23) - 127;  // вычисляем scale
  if (exp > 95 || exp < -94)
    return 1;  // если экспанента слишком большая или маленькая, то ошибка

  // домножаем src на 10 до тех пор пока не появиться
  // целое число. Запоминаем скейл
  int scale = 0;
  for (; !((int)src); src *= 10, scale++)
    ;

  // домножаем src на 10 до тех пор пока не появиться
  // 8 цифр до запятой. Запоминаем скейл
  for (; src < 10000000; src *= 10, scale++)
    ;

  fu.f = src;

  // вычисляем новый скейл нового src числа
  // если scale слишком большой или маленький то ошибка
  exp = ((fu.u & ~MINUS) >> 23) - 127;
  if (exp < -94 || scale > 28) return 1;

  // создаем маску с помощью которой будем побитово
  // считывать новый src
  uint32_t mask = 0x400000;

  // если скейл нашего нового src меньше нуля то инвертируем знак скейла src
  if (exp < 0) exp = -exp;

  // (может слишком далеко ставлю бит?) ставим самый дальний
  // (скрытый) бит float в наш результат
  temp_dec.bits[exp / 32] |= 1 << exp % 32;
  exp--;

  // пока скейл нашего src больше нуля, считываем бит
  // из src и вставляем его на свое место (после того
  // первого скрытого бита) по очереди в результат
  for (; exp > 0; exp--, mask >>= 1) {
    temp_dec.bits[exp / 32] |= (fu.u & mask) ? 1 << exp % 32 : 0;
  }

  // записываем заранее просчитанный скейл в децимал
  temp_dec.bits[3] |= scale << 16;
  *dst = temp_dec;
  return 0;
}

// округление но в сторону минус бесконечности
int s21_floor(s21_decimal value, s21_decimal *result) {
  work_decimal dec_work = decimal_to_work(value);

  int trash = 0;
  int scale =
      (((value.bits[3] & SC) >> 16) > 28) ? 28 : ((value.bits[3] & SC) >> 16);

  // убираем всю вещественную часть, но запоминаем последнюю цифру
  // и весь остаток в сумме
  for (int i = 0; i < scale; i++) {
    int last = pointright(&dec_work);
    trash += last;
  }

  // если общий остаток больше нуля и число отрицательное то
  // прибавляем единичку, чтобы сделать наше отрицательное
  // число ближе к минус бесконечности
  if (trash > 0 && value.bits[3] & MINUS) {
    dec_work.bits[0]++;
    getoverflow(&dec_work);
  }
  *result = work_to_decimal(dec_work);
  result->bits[3] = value.bits[3] & MINUS;
  return 0;
}


s21_decimal s21_round_banking(s21_decimal integral, s21_decimal fractional) {
    s21_decimal zerofive = {{5,0,0,0x00010000}};
    s21_decimal result;

    if (s21_is_equal(fractional, zerofive)) {
        // Если дробная часть ровно 0.5
        if ((integral.bits[0] & 1) != 1) {
            // Если целая часть четная, то оставляем её
            result = integral;
        } else {
            // Если целая часть нечетная, то увеличиваем её на 1
            s21_add(integral, (s21_decimal){{1,0,0,0}}, &result);
        }
    } else if (s21_is_greater(fractional, zerofive)) {
        // Если дробная часть > 0.5, то увеличиваем целую часть на 1
         s21_add(integral, (s21_decimal){{1,0,0,0}}, &result);
    } else {
        // Если дробная часть < 0.5, то оставляем целую часть без изменений
        result = integral;
    }

    return result;
}

// для округления используем банковского округление,
// то есть округление в сторону чётных
int s21_round(s21_decimal value, s21_decimal *result) {

 int error = 0;
  int scale = (value.bits[3] & SC) >> 16;
    if (!result) {
        // Если указатель на decimal является NULL
        error = 1;
    } else if (scale > 28 || scale < 0 || (value.bits[3] & FIRST) || (value.bits[3] & SECOND)) {
        // Проверяем, что value является корректными decimal
        error = 1;
        *result = (s21_decimal){{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x7FFFFFFF}};
    } else {
        // В остальных случаях округляем
        *result = (s21_decimal){{0,0,0,0}};
        int sign = value.bits[3] & MINUS;
        s21_decimal fractional;
        s21_decimal value_unsigned_truncated;
        // Убираем знак

        s21_decimal value_unsigned = value;
        value_unsigned.bits[3] = value.bits[3] & ~MINUS;
        // Убираем дробную часть числа
        s21_truncate(value_unsigned, &value_unsigned_truncated);

        // Считаем убранную дробную часть числа
        s21_sub(value_unsigned, value_unsigned_truncated, &fractional);

        // Производим округление, исходя из дробной части числа
        value_unsigned_truncated = s21_round_banking(value_unsigned_truncated, fractional);

        *result = value_unsigned_truncated;
        // Возвращаем знак
        result->bits[3] |= sign;
    }

    return error;
}

// просто делаем s21_floor но без знака. Знак потом
// возвращаем. Так получается что мы в любом случае
// просто отбрасываем вещественную часть
int s21_truncate(s21_decimal value, s21_decimal *result) {
  int sign = value.bits[3] & MINUS;
  value.bits[3] &= ~MINUS;
  s21_floor(value, result);
  result->bits[3] |= sign;
  return 0;
}

// инвертируем знаковый бит в децимал
int s21_negate(s21_decimal value, s21_decimal *result) {
  value.bits[3] =
      (value.bits[3] & MINUS) ? value.bits[3] & ~MINUS : value.bits[3] | MINUS;
  *result = value;
  return 0;
}