START
  ↓
Read Front, Left and Right distances
  ↓
Is Front > 5 cm?
  │
  ├── YES → Move Forward
  │
  └── NO
       ↓
     Stop
       ↓
 Is Left > Right?
   │          │
  YES         NO
   ↓           ↓
Turn Left   Is Right > 5 cm?
               │
          ┌────┴────┐
         YES       NO
          ↓         ↓
      Turn Right  Move Backward
