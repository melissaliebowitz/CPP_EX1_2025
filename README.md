
# מטלה 1 - תכנות מערכות 2
בחלק הראשון של המטלה התבקשנו לממש גרפים על ידי רשימת שכנויות.
במימוש שלי, התחלתי במימוש של מחלקה "צלע" (Edge) שמייצגת צלע בגרף שלכל צלע יש שני קודקודים ומשקל. מחלקה זו היא רק קובץ header מכיוון שהיא מחלקה קטנה עם מתודות מאוד בסיסיות וקצרות ולכן לא צריך קובץ מקור שלם. 
אחר כך, יצרתי מחלקה שממשת רשימת מקושרת (AjdList) של צלעות.
בסוף השתשמשתי במחלקות "Edge" ו-"AdjList" כדי ליצור את הגרף שלי. הגרף הוא בעצם מערך של רשימות מקושרות של צלעות שבו כל אינדקס במערך מייצג קודקוד, והרשימה המקושרת באותה התא במערך היא כל הצלעות שיוצאות מאותה הקודקוד.

בחלק השני של המטלה התבקשנו לממש 5 אלגורתמים (BFS, DFS, Dijsktra, Prim, Kruskal) שונים בלי להשתמש בספריות הסטנדרטיות vector ו-stack.
התחלתי במימוש של המבני נתונים הנדרשים לאלגוריתמים. כל מבני נתונים ממומש במחלקה נפרדת ובקובץ נפרד כדי לשמור על מודולריות הקוד.
המבני נתונים הם תור, מסחנית, תור עדיפויות פשוטה ו- union find פשוט. לכל מבני נתונים יש את המתודות הנדרשות בשביל שהאלגוריתם המתאים ירוץ בלי דגש מיוחד לסיבוכיות הזמן ריצה.
יצרתי מחלקה אלגוריתמים (Algorithms) שבו ממומש את האלגורתמים הנדרשים. כל אלגוריתם משתמש במבני נתונים המתאים. 
לכל מחלקה יש קובץ header וקובץ מקור. בקבצי header מוצהרים שדות ומתודות של המחלקה וממומשים מתודות בסיסיות וקצרות (כמו: getters) ובקבצי מקור יש את המימושים של הבנאיים והמתודות. 
לכל מחלקה כתבתי קובץ טסטים, בכל קובץ טסט יש בדיקות יחידה עבור כל המתודות במחלקה. השתמשתי ב-doctest כדי לכתוב את הטסטים שלי.  

חלקתי את הפרוייקט לכמה תיקיות:
תיקיית "include" שנמצאים הקבצי header, 
תיקיית "src" שבו נמצאים כל קבצי המקור (cpp.), 
תיקיית "tests" שבו נמצאים כל הטסטים ואת "doctest.h", 
החלוקה הזאת הגיונית ושומרת על סדר.






