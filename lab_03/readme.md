`За лабу получил 20/20` **НО**.

1. Тассов может придраться к загрузке, а именно к тому, что файл-лоадер слишком умный и дергает билдера. Что хочет Тассов: директор получает от лоадера примитивы и сам вызывает билдера.
2. Тассов может захотеть матрицы преобразований
3. Тут костыльненько реализован выбор модели/камеры для действий над ним. Тассов хотел, чтобы сцена держала один композит объектов, а определяла, что это(камера или модель) на основе `isVisible()`. Тассов сам захотел такой костыль... 
4. К п.3: к тому же из-за этого пришлось в UI сделать мусорку из объектов. Но работает - не трогай, как говорится. Тем более, что Тассову по\*уй на интерфейс. 

**Главные преимущества:**
1. Сцена не наследуется от объекта. Если кто-то сдал ему не так, то Тассов просто не заметил, иначе бы снес лицо. 
2. DrawManager не наследуется от Посетителя, если кто-то сдал с наследованием, то аналогично п.1.