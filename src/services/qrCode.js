import { QRCodeStyling } from "qr-code-styling";

const genQRCode = ({
  data,
  image,
  dataOptions,
  backgroundOptions,
  imageOptions,
}) =>
  new QRCodeStyling({
    width: 300,
    height: 300,
    data: data,
    image: image || null,
    dataOptions: dataOptions || { color: "#4267b2", type: "rounded" },
    backgroundOptions: backgroundOptions || { color: "#e9ebee" },
    imageOptions: imageOptions || { crossOrigin: "anonymous", margin: 20 },
  });

const renderQRCode = (qrCode, target) => {
  const targetNode = document.getElementById(target);
  qrCode.append(targetNode);
  return targetNode;
};

export default { genQRCode, renderQRCode };
