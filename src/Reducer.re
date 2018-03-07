open Types;

let pre = (_, state: rootState, action: Actions.all) : rootState =>
  switch action {
  | Tick =>
    let (aliens, shots) =
      Colision.findNotCollided(state.alien.aliens, state.shot.shots);
    {
      ...state,
      shot: {
        ...state.shot,
        shots
      },
      alien: {
        ...state.alien,
        aliens
      }
    };
  | BgImageLoaded(img) => {
      ...state,
      screen: {
        ...state.screen,
        potentialBg: Some(img)
      }
    }
  | _ => state
  };

let post = (_, state: rootState, _) : rootState => state;