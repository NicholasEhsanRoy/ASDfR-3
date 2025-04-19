import math
import matplotlib.pyplot as plt
import matplotlib.animation as animation
#python version Python 3.13.2
# encoder has 4096 ticks per turn
# encoder goes from 0 : 16383 or 16384 ticks, then resets. so a full encoder buffer contains 4 turns.
# the wheel has 15.58 gear ratio, so a 1 wheel turn is 15.58 encoder turns. so a full wheel turn conatins 15.58*4096=63815.68 ticks total
# so the wheel contains 3.895 buffers.
# soft encoder always resets at 14664 from the hard encoder

# === SoftEncoder Class === converts a hard incoder value to a soft encoder value that accounts for the gear ratio. 
class SoftEncoder:
    def __init__(self, hard_encoder_max=16383, counts_per_revolution=63816):
        self.hard_encoder_max = hard_encoder_max
        self.counts_per_revolution = counts_per_revolution
        self.max_soft_encoder_value = (16383 * 3.895)
        self.wrap_count = 0 
        self.prev_hard = -99999999
        self.soft_encoder = 0
        self.direction = 1

    def update_from_hard_encoder(self, new_hard):
        if self.prev_hard == -99999999:
            self.prev_hard = new_hard
            return

        diff = new_hard - self.prev_hard
        half_range = (self.hard_encoder_max + 1) // 2

        # Handle wraparound from hardware encoder
        if diff > half_range:
            diff -= (self.hard_encoder_max + 1)
            self.wrap_count -= 1
            self.direction = -1
        elif diff < -half_range:
            diff += (self.hard_encoder_max + 1)
            self.wrap_count += 1
            self.direction = 1

        self.soft_encoder = (self.soft_encoder + diff)
        # Wrap soft encoder from 0 to max, in both directions, avoid using mod so the code can be easily moved to cpp without changing math equations.
        # if self.soft_encoder > self.max_soft_encoder_value :
        #     self.soft_encoder = 0

        # if self.soft_encoder  < 0:
        #     self.soft_encoder = self.max_soft_encoder_value - 1

        self.prev_hard = new_hard

    def get_angle_radians(self):
        fractional_turn = (self.soft_encoder ) / self.counts_per_revolution
        return fractional_turn * 2 * math.pi
    
    def get_wrap_count(self):
        return self.wrap_count

# === Setup Subplots ===
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(10, 5))
for ax in [ax1, ax2]:
    ax.set_aspect('equal')
    ax.set_xlim(-1.5, 1.5)
    ax.set_ylim(-1.5, 1.5)
    ax.axis('off')
    ax.plot([-1.1, 1.1], [0, 0], color='black', linestyle='--', linewidth=1)
    ax.plot([0, 0], [-1.1, 1.1], color='black', linestyle='--', linewidth=1)

# === Soft Encoder Visualization (Left) ===
soft_circle = plt.Circle((0, 0), 1, color='lightgray', fill=False)
ax1.add_artist(soft_circle)
soft_arrow_line, = ax1.plot([], [], color='blue', linewidth=2)
wrap_arrow_line, = ax1.plot([], [], color='red', linewidth=2, linestyle='dashed')
angle_text = ax1.text(0, 1.25, '', fontsize=12, ha='center')
hard_text = ax1.text(0, -1.4, '', fontsize=10, ha='center', color='gray')
soft_text = ax1.text(0, -1.3, '', fontsize=10, ha='center', color='gray')
soft_text_zero_cross = ax1.text(0, -1.5, '', fontsize=10, ha='center', color='gray')

# === Hard Encoder Visualization (Right) ===
# === Hard Encoder Visualization (Right) ===
hard_circle = plt.Circle((0, 0), 1, color='lightgray', fill=False)
ax2.add_artist(hard_circle)
hard_arrow_line, = ax2.plot([], [], color='green', linewidth=2)
hard_label = ax2.text(0, 1.25, '', fontsize=12, ha='center')
hard_text_angle = ax2.text(0, -1.3, '', fontsize=10, ha='center', color='gray')
hard_text_value = ax2.text(0, -1.5, '', fontsize=10, ha='center', color='gray')


# === Simulation Variables ===
encoder = SoftEncoder()
hard_encoder_value = 16030
direction =  1
step_size = 200
frame_count = 0
# === Animation Update ===
def update(frame):
    global hard_encoder_value, direction,frame_count
    frame_count = frame_count + 1
    if frame_count % 400 == 0:
        direction = direction * -1
    hard_encoder_value = (hard_encoder_value + direction * step_size) % (encoder.hard_encoder_max + 1)
    encoder.update_from_hard_encoder(hard_encoder_value)

    # --- Soft Encoder Arrow ---
    angle = encoder.get_angle_radians()
    x = math.cos(angle)
    y = math.sin(angle)
    soft_arrow_line.set_data([0, x], [0, y])

    # Red reset arrow (where hard encoder is zero in soft space)
    reset_angle = angle - ((hard_encoder_value % encoder.counts_per_revolution) / encoder.counts_per_revolution * 2 * math.pi)
    if direction == 1:
        reset_angle = reset_angle + (0.5 * math.pi)
    reset_angle %= 2 * math.pi
    rx = math.cos(reset_angle)
    ry = math.sin(reset_angle)
    wrap_arrow_line.set_data([0, rx], [0, ry])

    angle_text.set_text(f"Wheel Position Angle: {angle:.3f} rad ({angle / math.pi:.4f} π)")
    hard_text.set_text(f"Hard Encoder: {hard_encoder_value}")
    soft_text.set_text(f"Soft Encoder: {encoder.soft_encoder}")
    soft_text_zero_cross.set_text(f"Zero cross hard encoder: {encoder.get_wrap_count()}")

    # --- Hard Encoder Arrow ---
    # 0 rad = 3 o'clock (standard coordinate system)
    hard_angle = (hard_encoder_value / 16383.0) * 2 * math.pi
    hx = math.cos(hard_angle)
    hy = math.sin(hard_angle)
    hard_arrow_line.set_data([0, hx], [0, hy])

    hard_label.set_text("Hard Encoder")
    hard_text_angle.set_text(f"{hard_angle:.3f} rad ({hard_angle / math.pi:.4f} π)")
    hard_text_value.set_text(f"Value: {hard_encoder_value}")

    return soft_arrow_line, wrap_arrow_line, hard_arrow_line, angle_text, hard_text
# Animate
ani = animation.FuncAnimation(fig, update, interval=1)
plt.suptitle("Soft Encoder (Left) & Hard Encoder (Right)")
plt.show()

