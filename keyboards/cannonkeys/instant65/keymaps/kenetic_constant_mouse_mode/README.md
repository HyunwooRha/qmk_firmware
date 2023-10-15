# Collective Changes
## Added mouse mode (a combined version of the kenetic mouse and constant mouse modes)
* The mouse is controlled by the ``i`` key, the ``j`` key, the ``k`` key, and the ``l`` key
    * The ``i`` key moves the mouse up
    
    * The ``j`` key moves the mouse left
    
    * The ``k`` key moves the mouse down
    
    * The ``l`` key moves the mouse right
    
* The mouse buttons are the ``u`` key and the ``o`` key
    * Alternatively, the mouse buttons can be the ``x`` key and the ``z`` keys.
    
    * Note that unlike the ``u`` and ``o`` keys, the ``x`` and ``z`` keys are ``right`` and ``left`` mouse buttons, respectively.
    
* The mouse speed is controlled by the ``a`` key, the ``s`` key, and the ``d`` key, each one progressively increasing speed but *only* when held down
    * This will lock the mouse speed

* Keys ``n`` and ``m`` are the ``scroll up`` and ``scroll down`` keys, respectively, also being affected by the mouse acceleration keys

* The default ``page up`` and ``page down`` remain unaffected

## Added tap dancing for the ``left alt`` key
* Tapping the ``alt`` key turns the ``number row`` into the ``function row`` for a brief period of time

* Holding the ``alt`` key remains unchanged

* Tapping then holding the ``alt`` key is thus equivalent to holding the ``alt`` key while having the ``number row`` as the ``function row``.

* This lets you do commands such as ``alt + f4`` by tapping the ``alt`` key, then holding the ``alt`` key, then pressing the ``4`` key.

* Added a toggle for the ``function row`` via tapping the ``right fn`` key two times
    * Note that holding the key remains unchanged

* Replaced the ``windows button`` to activate a different layer

    * While in this state, holding the ``right control`` key enables the mouse controls

        * You must hold the ``right control`` key to use the mouse controls but not the ``windows button``

    * Tapping the the ``left alt`` key activates the ``windows button``

    * Keys ``i``, ``j``, ``k``, and ``l`` will be the ``arrow keys`` but the dedicated ``arrow keys`` will remain unaffected
    
## Other changes
* While using any key that has a unique function (i.e. the ``windows button`` or the ``left alt`` key), the insert key will be replaced with the ``insert`` key

* To use the `` ` `` key and the ``~`` key, you must hold the ``windows button`` key and the ``esc`` key. Press the ``shift`` key to access the ``~`` character

* You cannot use the ``windows button`` while having the ``function row`` active

    * This can easily be changed by changing the ``KC_NO`` to ``KC_LGUI`` for layer 2 in the *keymap.c* file

    * In order to save changes, you must compile the firmware and flash the keyboard
    
* You can use Print Screen by holding or toggling the ``right fn`` key and pressing the ``del`` key