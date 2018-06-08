##

Download

```ruby
live_loop :foo do
  use_real_time
  a, b, c, d= sync "/osc/trigger/prophet"
  synth :tb303, note: a, attack: b, sustain: c*0.5, release: d
end
```
