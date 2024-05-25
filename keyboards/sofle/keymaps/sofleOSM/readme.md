keymap -> ![current keymap](./keymap.svg)

The above keymap should be a self sufficient explanantion of the keymap, below are my thoughts on this version of the keymap

main goal of this layout is to move the effort from left side to the right side
The layout is intentionally as asymmentric and favoured towards right side as possible, in the context of keys which are to be held, since my hands are not symmentric in how they get things done so doesnt make sense the keyboard layout should be symmentric

space is used by the dominant thumb key, instead of on the left thumb key 


shift key is moved to the dominant thumb key so that it can be used for both sides

in numbers layer alt key is added since I use that key for the purpose of moving between workspaces with alt + num, since shift key is not needed in the numbers layer, it is replaced with the alt key

mapped esc to j, k key as a combo, it was better than I expected, there is some muscle memory which still takes me to using the left pinky but using j,k feels good

Unintended consequence of moving to tab to number layer was autocomplete is more comfy&fun on this layer, using ring finger compared using on the left pinkie

Working on this keymap feels like I made a mistake jumping into 40% keyboard rabbit hole (╯°□°)╯︵ ┻━┻

Nevertheless, it was fun thinking throught this layout, though it felt like white board mastrubation after I came up with the layout, like primeagen describes when talking about architectural designs, There are many other things I could be improving upon rather than the keymap on a freaking keyboard, like the Ben horowitz author of "The hard thing about hard things" says you should work on developing lead bullets to beat the competetion, rather than thinking about silver bullets

<picture>
    <source srcset="https://tenor.com/Hgjy.gif">
    <img alt="white board mastrubation">
</picture>

Observations
- Holding shift in base layer and going to num layer makes the held shift key to behave as shift key, this is a neat feature which could be used to combine number and symbol layer.
    - Thing would be getting hang of moving thumbs accordingly
    - this goes other way too, holding alt key in num layer and going back to base layer, the held key will behave as alt key
    - Will need more time to get it as muscle memory, though not sure how much it would be ergonomic
- Using one shift key on thumb for both sides is good.
- Using jk combo for esc is way too good, need to see more key code to assign to combos

Things I am trying out in this layout
- Assinging combos for ent, tab, bks
    - ent - M,
    - tab - UI
    - There are other combos I would like to try but at this point this feels the best one to use and get habituated to
- Moving number to the homerow so that I can use this in combination with the symbol keys
    - This also means that I moved the mods to the top row, For now the purpose is for workspace, but also wanting to a single hand way to get access to all modifers when having mouse on right hand, so most probably I would leave it as is, may be move it to bottom row
- Main thing to get hang of in this layout would be getting hangoff using shift and alt on the layers
- Moving back to inverted T arrow keys, I feel this makes more sense to me, I get jk works in vim and browser, but in terminal in other places, I like the inverted T llets give this a try

Tried but was not working
- One shot mods of qmk, activating mods in one layer and moving to another layer makes it difficult to register them, it is finicky.
    - it does not work as callums mods
- Shift works well on right thumb rather than left thumb key

references used for building this keyboard
https://github.com/ghostbuster91/blogposts/blob/main/42-keys/main.md

https://johnlindquist.com/an-opinionated-guide-to-keyboard-thumb-keys/

http://www.keyboard-layout-editor.com/#/gists/016b11b6fc11fa1cb9306338a26e71f9

http://xahlee.info/kbd/banish_key_chords.html -> this was the main inspiration for using sticky keys or one shot mods, I wanted to use chording which feels good compared to just pressing all the keys together, his other posts are also insightful on ergonomics

https://github.com/callum-oakley/qmk_firmware/tree/master/users/callum -> callums one shot mods, which donot think about timing issues which come with using home row mods, or qmk's one shot mods, though currently there is no support from zmk on this ʕ ಡ ﹏ ಡ ʔ

People blogging about 34 key layout, make it feel like it is simple to use, but when implementing that layout but damn it feels difficult to get it right when trying to use it, it feels like they are intentionally saying it as easy to get more company in their misery

https://www.rousette.org.uk/archives/ferris-sweep-keyboard-and-layout/
https://www.jonashietala.se/blog/2021/06/03/the-t-34-keyboard-layout/
https://ryan.himmelwright.net/post/building-34-key-layout/

Like I said, you can go to the moon without a computer, so, you know, the thing we are talking about is 40% keyboard, which means only 40 keys. It's very hard to type Chinese, Japanse, Russian with 40% keyboard. It's like doubling your work. Yeah, you can. But if you need to type that two hours a day you gonna see a doctor within a month. (Xah Lee) -- Jorne wiki  https://github.com/joric/jorne/wiki

jokes aside it was fun reading through the posts of users who are ahead in the keyboard, and their other posts related to other aspects of optimisation was fun too

I think I can go for 34 key layout but yeah it would take some time, and 36 is easier goal to have
