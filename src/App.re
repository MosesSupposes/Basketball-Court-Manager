[@react.component]
let make = () => {
  let teams: list(Team.t) = [
    {name: "Mambas", captain: "Kobe Bryant"},
    {name: "Moses and the Mosets", captain: "Moses Samuel"},
    {name: "The Mini Mikes", captain: "Michael Sadaghyani"},
  ];
  <main> <TeamList teams /> <WaitTime queue=teams /> </main>;
};
