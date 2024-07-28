`int var1 : 3;` declares a bit-field, and you can not apply `operator&` to a bit-field. §[class.bit]¶3 in the standard:

> The address-of operator `&` shall not be applied to a bit-field, so there are no pointers to bit-fields.