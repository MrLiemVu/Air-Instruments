# From https://filterpy.readthedocs.io/en/latest/kalman/KalmanFilter.html
# Github Repo with a bunch of different tiypes of filters we can explore: https://github.com/rlabbe/Kalman-and-Bayesian-Filters-in-Python
from filterpy.kalman import KalmanFilter
from filterpy.common import Q_discrete_white_noise

f = KalmanFilter (dim_x=2, dim_z=1)
f.x = np.array([[2.],    # Initial position
                [0.]])   # Initial velocity

f.F = np.array([[1.,1.], # State Transition Matrix
                [0.,1.]])

f.H = np.array([[1.,0.]]) # Measurement Function

f.P *= 1000. # Covariance Matrix (Here I take advantage of the fact that P already contains np.eye(dim_x), and just multiply by the uncertainty)

f.R = 5 # Measurement Noise (Scalar)

f.Q = Q_discrete_white_noise(dim=2, dt=0.1, var=0.13) # Process Noise

while True:
    z, R = read_sensor()
    x, P = predict(x, P, F, Q)
    x, P = update(x, P, z, R, H)
