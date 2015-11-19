# DrinkDroid
DrinkDroid is a user-friendly beverage dispenser which mixes a variety of drinks on demand using an arduino, some ball valves, and a few servos.
DrinkDroid has 3 modes of operation:
  - Pour a mixed drink (Mixes one type of spirit with one type of mix)
  - Pour a shot (Pours exactly 1.5 oz of spirit)
  - Pour a mixer or complex drink ( Pours a shot of mixer or mixes multiple types of spirits with multiple types of mixer)

This machine was designed to pour the same exact amounts of liquid each time, despite the change in pressure caused by the decreasing volumn. Each time a shot is poured, the DrinkDroid adjusts for the displaced liquid, and recalculates the time the valve needs to be open to pour the same amount. These calculations are specific to the bottle sizes which were used.
