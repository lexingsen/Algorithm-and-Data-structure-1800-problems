1 /**
  2  * strlen - Find the length of a string
  3  * @s: The string to be sized
  4  */
  5 size_t strlen(const char *s)
  6 {
  7     const char *sc;
  8 
  9     for (sc = s; *sc != '\0'; ++sc)
 10         /* nothing */;
 11     return sc - s;
 12 }
 13 
 14 /**
 15  * strnlen - Find the length of a length-limited string
 16  * @s: The string to be sized
 17  * @count: The maximum number of bytes to search
 18  */
 19 size_t strnlen(const char *s, size_t count)
 20 {
 21     const char *sc;
 22 
 23     for (sc = s; count-- && *sc != '\0'; ++sc)
 24         /* nothing */;
 25     return sc - s;
 26 }
 27 
 28 /**
 29  * strcpy - Copy a %NUL terminated string
 30  * @dest: Where to copy the string to
 31  * @src: Where to copy the string from
 32  */
 33 char *strcpy(char *dest, const char *src)
 34 {
 35     char *tmp = dest;
 36 
 37     while ((*dest++ = *src++) != '\0')
 38         /* nothing */;
 39     return tmp;
 40 }
 41 
 42 /**
 43  * strncpy - Copy a length-limited, %NUL-terminated string
 44  * @dest: Where to copy the string to
 45  * @src: Where to copy the string from
 46  * @count: The maximum number of bytes to copy
 47  *
 48  * The result is not %NUL-terminated if the source exceeds
 49  * @count bytes.
 50  *
 51  * In the case where the length of @src is less than  that  of
 52  * count, the remainder of @dest will be padded with %NUL.
 53  *
 54  */
 55 char *strncpy(char *dest, const char *src, size_t count)
 56 {
 57     char *tmp = dest;
 58 
 59     while (count) {
 60         if ((*tmp = *src) != 0) /* src����ͷ�����Լ�ʹ��dest������'\0'�� */
 61             src++;
 62         tmp++;
 63         count--;
 64     }
 65     return dest;
 66 }
 67 
 68 /**
 69  * strcat - Append one %NUL-terminated string to another
 70  * @dest: The string to be appended to
 71  * @src: The string to append to it
 72  */
 73 char *strcat(char *dest, const char *src)
 74 {
 75     char *tmp = dest;
 76 
 77     while (*dest)
 78         dest++;
 79     while ((*dest++ = *src++) != '\0')
 80         ;
 81     return tmp;
 82 }
 83 
 84 /**
 85  * strncat - Append a length-limited, %NUL-terminated string to another
 86  * @dest: The string to be appended to
 87  * @src: The string to append to it
 88  * @count: The maximum numbers of bytes to copy
 89  *
 90  * Note that in contrast to strncpy(), strncat() ensures the result is
 91  * terminated.
 92  */
 93 char *strncat(char *dest, const char *src, size_t count)
 94 {
 95     char *tmp = dest;
 96 
 97     if (count) {
 98         while (*dest)
 99             dest++;
100         while ((*dest++ = *src++) != 0) {
101             if (--count == 0) {
102                 *dest = '\0';
103                 break;
104             }
105         }
106     }
107     return tmp;
108 }
109 
110 /**
111  * strcmp - Compare two strings
112  * @cs: One string
113  * @ct: Another string
114  */
115 int strcmp(const char *cs, const char *ct)
116 {
117     unsigned char c1, c2;
118 
119     while (1) {
120         c1 = *cs++;
121         c2 = *ct++;
122         if (c1 != c2)
123             return c1 < c2 ? -1 : 1;
124         if (!c1)
125             break;
126     }
127     return 0;
128 }
129 
130 /**
131  * strncmp - Compare two length-limited strings
132  * @cs: One string
133  * @ct: Another string
134  * @count: The maximum number of bytes to compare
135  */
136 int strncmp(const char *cs, const char *ct, size_t count)
137 {
138     unsigned char c1, c2;
139 
140     while (count) {
141         c1 = *cs++;
142         c2 = *ct++;
143         if (c1 != c2)
144             return c1 < c2 ? -1 : 1;
145         if (!c1)
146             break;
147         count--;
148     }
149     return 0;
150 }
151 
152 /**
153  * strchr - Find the first occurrence of a character in a string
154  * @s: The string to be searched
155  * @c: The character to search for
156  */
157 char *strchr(const char *s, int c)
158 {
159     for (; *s != (char)c; ++s)
160         if (*s == '\0')
161             return NULL;
162     return (char *)s;
163 }
164 
165 /**
166  * strnchr - Find a character in a length limited string
167  * @s: The string to be searched
168  * @count: The number of characters to be searched
169  * @c: The character to search for
170  */
171 char *strnchr(const char *s, size_t count, int c)
172 {
173     for (; count-- && *s != '\0'; ++s)
174         if (*s == (char)c)
175             return (char *)s;
176     return NULL;
177 }
178 
179 /**
180  * memcmp - Compare two areas of memory
181  * @cs: One area of memory
182  * @ct: Another area of memory
183  * @count: The size of the area.
184  */
185 int memcmp(const void *cs, const void *ct, size_t count)
186 {
187     const unsigned char *su1, *su2;
188     int res = 0;
189 
190     for (su1 = cs, su2 = ct; 0 < count; ++su1, ++su2, count--)
191         if ((res = *su1 - *su2) != 0)
192             break;
193     return res;
194 }
195 
196 /**
197  * memcpy - Copy one area of memory to another
198  * @dest: Where to copy to
199  * @src: Where to copy from
200  * @count: The size of the area.
201  *
202  * You should not use this function to access IO space, use memcpy_toio()
203  * or memcpy_fromio() instead.
204  */
205 void *memcpy(void *dest, const void *src, size_t count)
206 {
207     char *tmp = dest;
208     const char *s = src;
209 
210     while (count--)
211         *tmp++ = *s++;
212     return dest;
213 }
214 
215 /* Not static to avoid a conflict with the prototype in the Linux headers. */
216 void *memmove(void *dest, const void *src, size_t size)
217 {
218     uint8_t *d = dest;
219     const uint8_t *s = src;
220     size_t i;
221     /* �жϵ�ַ�ߵ�, �ɳ����ص����� */
222     if (d < s) {
223         for (i = 0; i < size; ++i)
224             d[i] = s[i];
225     } else if (d > s) {
226         i = size;
227         while (i-- > 0)
228             d[i] = s[i];
229     }
230 
231     return dest;
232 }
233 
234 /**
235  * strstr - Find the first substring in a %NUL terminated string
236  * @s1: The string to be searched
237  * @s2: The string to search for
238  */
239 char *strstr(const char *s1, const char *s2)
240 {
241     size_t l1, l2;
242 
243     l2 = strlen(s2);
244     if (!l2)
245         return (char *)s1;
246     l1 = strlen(s1);
247     while (l1 >= l2) {
248         l1--;
249         if (!memcmp(s1, s2, l2))
250             return (char *)s1;
251         s1++;
252     }
253     return NULL;
254 }
255 
256 /**
257  * strnstr - Find the first substring in a length-limited string
258  * @s1: The string to be searched
259  * @s2: The string to search for
260  * @len: the maximum number of characters to search
261  */
262 char *strnstr(const char *s1, const char *s2, size_t len)
263 {
264     size_t l2;
265 
266     l2 = strlen(s2);
267     if (!l2)
268         return (char *)s1;
269     while (len >= l2) {
270         len--;
271         if (!memcmp(s1, s2, l2))
272             return (char *)s1;
273         s1++;
274     }
275     return NULL;
276 }
